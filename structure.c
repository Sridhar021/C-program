/*A structure a is user defined data type that allows grouping of variables of different types under a single name.*/

#include<stdio.h>
struct Student 
{
	char name[50];
	int rno;
	int marks;
};

int main()
{
	struct Student s;
	printf("Enter Name: ");
	fgets(s.name,sizeof(s.name),stdin);
	printf("Enter roll number: ");
	scanf("%d",&s.rno);
	printf("Enter marks: ");
	scanf("%d",&s.marks);
	printf("\n Student Information\n");
	printf("Name:%s\n",s.name);
	printf("Rollno:%d\n",s.rno);
	printf("Marks:%d\n",s.marks);
	
	return 0;
}
	
	


