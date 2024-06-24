#include<stdio.h>

void ssort(int arr[],int s)
{
	int i,j,min,temp;
	for(i=0;i<s-1;i++)
	{
	min=i;
	for(j=i+1;j<s;j++){
	if (arr[j]<arr[min]){
	min=j;}
	}
	if(min!=i)
	{
	temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
	}
}
}
	
int main()
{
int arr[]={10,7,6,9,8};
int s=sizeof(arr)/sizeof(arr[0]);
printf("Original array :\n");
for(int i=0;i<s;i++){
printf("%d", arr[i]);
}
printf("\n");
ssort(arr,s);
printf("Sorted array :\n");
for(int i=0;i<s;i++){
printf("%d", arr[i]);
}
return 0;
}

