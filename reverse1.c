#include<stdio.h>
#include<string.h>
int main()
{
	char str[100]="string";
	int len;
	printf("Original string %s ",str);
	len=strlen(str);
	for(int i=0,j=len-1;i<=j;i++,j--)
	{
	char c= str[i];
	str[i]=str[j];
	str[j]=c;
	}
	printf("Reversed string %s ",str);
	return 0;
}
 
	
