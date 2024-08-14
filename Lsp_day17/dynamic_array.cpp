#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;          // Pointer to the array data
    size_t size;      // Current number of elements
    size_t capacity;  // Current capacity of the array

    // Resizes the array to the specified new capacity
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Constructor to initialize the array with a specified capacity
    DynamicArray(size_t initialCapacity = 4) : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    // Destructor to clean up allocated memory
    ~DynamicArray() {
        delete[] data;
    }

    // Inserts an element at the end of the array
    void insert(const T& value) {
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity when needed
        }
        data[size++] = value;
    }

    // Deletes an element at a specified index
    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Clears the array, effectively removing all elements
    void clear() {
        size = 0;
    }

    // Returns the current number of elements
    size_t getSize() const {
        return size;
    }

    // Returns the element at a specified index
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Const version of the index operator
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Displays the contents of the array
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    DynamicArray<int> arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    std::cout << "Array contents: ";
    arr.display();

    arr.remove(1);
    std::cout << "After removing element at index 1: ";
    arr.display();

    arr.insert(50);
    std::cout << "After inserting 50: ";
    arr.display();

    arr.clear();
    std::cout << "After clearing the array: ";
    arr.display();

    return 0;
}