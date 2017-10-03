#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int r,c,m=0,n=0,i,j,**a;
	printf("Row     : ");
	scanf("%d",&r);
	printf("Coloumn : ");
	scanf("%d",&c);
	a=malloc(sizeof(int*)*r);
	for(i=0;i<r;i++)
		a[i]=malloc(sizeof(int)*c);
	printf("Elements to array : ");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	printf("Matrix :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%2d ",a[i][j]);
		printf("\n");
	}
	printf("spiral print : ");
	while(m<r && n<c)
	{

		for(i=n;i<c;i++)
			printf("%2d, ",a[m][i]);
		m++; 

		for(i=m;i<r;i++)
			printf("%2d, ",a[i][c-1]);
		c--;
		if(m<r)
		{
			for(i=c-1;i>=n;i--)
				printf("%2d, ",a[r-1][i]);
			r--;
		}
		if(n<c)
		{
			for(i=r-1;i>=m;i--)
				printf("%2d, ",a[i][n]);
			n++;
		}
	}
	printf("\b\b  \n");
	return 0;
}
