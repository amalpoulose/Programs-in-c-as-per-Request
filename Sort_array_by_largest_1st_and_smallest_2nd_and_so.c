/* Sort array such that 1st element is largest and 2nd is smallest element and so on
   By Amal Poulose amalpoulose95@hotmail.com  +919446047003*/
#include<stdio.h>
int main(void)
{
	int a[100],i,j,n,t;
	printf("Array size : ");
	scanf("%d",&n);
	printf("Enter array elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array elements : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);       
	printf("\n");
	/* Selection sort is used because the 1st element would be fixed after one iteration of outer loop*/ 
	for(i=0;i<n-1;i++)                     
		for(j=i+1;j<n;j++)
		{
			if(i%2)                   // if i value is odd then smallest value in remaining index values is goes to ith index
			{  if(a[i]>a[j])
				a[i]=a[i]+a[j]-(a[j]=a[i]);
			}
			else                   //  if i value is even then largest value in remaining index values is goes to ith index
			{
				if(a[i]<a[j])   
					a[i]=a[i]+a[j]-(a[j]=a[i]);
			}
		} 
	printf("Array elements : \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);       
	printf("\n");
	return 0;
}
