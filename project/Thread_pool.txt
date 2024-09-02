#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Task structure
typedef struct {
    void (*function)(void *);
    void *arg;
} task_t;

// Task queue structure
typedef struct {
    task_t *tasks;
    int task_count;
    int front;
    int rear;
    pthread_mutex_t lock;
    pthread_cond_t notify;
} task_queue_t;

// Thread pool structure
typedef struct {
    pthread_t *threads;
    task_queue_t queue;
    int thread_count;
    int shutdown;
} thread_pool_t;

// Function prototypes
thread_pool_t* thread_pool_create(int thread_count, int queue_size);
void thread_pool_add(thread_pool_t *pool, void (*function)(void *), void *arg);
void *thread_pool_worker(void *arg);
void thread_pool_destroy(thread_pool_t *pool);

// Thread pool creation
thread_pool_t* thread_pool_create(int thread_count, int queue_size) {
    thread_pool_t *pool = malloc(sizeof(thread_pool_t));
    pool->threads = malloc(sizeof(pthread_t) * thread_count);
    pool->queue.tasks = malloc(sizeof(task_t) * queue_size);
    pool->queue.task_count = queue_size;
    pool->queue.front = pool->queue.rear = 0;
    pthread_mutex_init(&(pool->queue.lock), NULL);
    pthread_cond_init(&(pool->queue.notify), NULL);
    pool->thread_count = thread_count;
    pool->shutdown = 0;

    // Create worker threads
    for(int i = 0; i < thread_count; i++) {
        pthread_create(&(pool->threads[i]), NULL, thread_pool_worker, (void*)pool);
    }
    return pool;
}

// Adding a task to the thread pool
void thread_pool_add(thread_pool_t *pool, void (*function)(void *), void *arg) {
    pthread_mutex_lock(&(pool->queue.lock));

    // Add task to queue
    pool->queue.tasks[pool->queue.rear].function = function;
    pool->queue.tasks[pool->queue.rear].arg = arg;
    pool->queue.rear = (pool->queue.rear + 1) % pool->queue.task_count;

    pthread_cond_signal(&(pool->queue.notify));
    pthread_mutex_unlock(&(pool->queue.lock));
}

// Worker thread function
void *thread_pool_worker(void *arg) {
    thread_pool_t *pool = (thread_pool_t *)arg;
    while(1) {
        pthread_mutex_lock(&(pool->queue.lock));

        // Wait for task
        while(pool->queue.front == pool->queue.rear && !pool->shutdown) {
            pthread_cond_wait(&(pool->queue.notify), &(pool->queue.lock));
        }

        // If shutdown, exit
        if(pool->shutdown) {
            pthread_mutex_unlock(&(pool->queue.lock));
            pthread_exit(NULL);
        }

        // Get task
        task_t task = pool->queue.tasks[pool->queue.front];
        pool->queue.front = (pool->queue.front + 1) % pool->queue.task_count;

        pthread_mutex_unlock(&(pool->queue.lock));

        // Execute task
        (*(task.function))(task.arg);
    }
    return NULL;
}

// Destroying the thread pool
void thread_pool_destroy(thread_pool_t *pool) {
    pthread_mutex_lock(&(pool->queue.lock));
    pool->shutdown = 1;

    pthread_cond_broadcast(&(pool->queue.notify));
    pthread_mutex_unlock(&(pool->queue.lock));

    for(int i = 0; i < pool->thread_count; i++) {
        pthread_join(pool->threads[i], NULL);
    }

    free(pool->threads);
    free(pool->queue.tasks);
    pthread_mutex_destroy(&(pool->queue.lock));
    pthread_cond_destroy(&(pool->queue.notify));
    free(pool);
}

// Example task function
void example_task(void *arg) {
    int num = *(int *)arg;
    printf("Task %d is being processed.\n", num);
    sleep(1); // Simulate task processing
}

int main() {
    thread_pool_t *pool = thread_pool_create(4, 10);

    for(int i = 0; i < 10; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i + 1;
        thread_pool_add(pool, example_task, (void *)arg);
    }

    sleep(5); // Wait for tasks to complete
    thread_pool_destroy(pool);
    return 0;
}