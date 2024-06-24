/*5)
A pointer is a variable that stores the memory address of another variable
pointers are declared using * operators*/

#include<stdio.h>

void swap(int *x,int* y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}

int main()
{
	int a,b;
	printf("Enter value 1:");
	scanf("%d",&a);
	printf("Enter value 2:");
	scanf("%d",&b);
	swap(&a,&b);
	printf("Swaped values are %d and %d ",a,b);
	return 0;
}

	
