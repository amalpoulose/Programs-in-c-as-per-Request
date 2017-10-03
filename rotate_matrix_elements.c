#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int r,c,m=0,n=0,i,j,**a,pre,cur;
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
	while(m<r && n<c)
	{
		if(m+1==r || n+1==c)
			break;
		pre=a[m+1][n];                       
			for(i=n;i<c;i++)
			{
				cur=a[m][i];
				a[m][i]=pre;
				pre=cur;
			}

		m++; 

		for(i=m;i<r;i++)
		{
			cur=a[i][c-1];
			a[i][c-1]=pre;
			pre=cur;
		}
		c--;
		if(m<r)
		{
			for(i=c-1;i>=n;i--)
			{
				cur=a[r-1][i];
				a[r-1][i]=pre;
				pre=cur;
			}
			r--;
		}
		if(n<c)
		{
			for(i=r-1;i>=m;i--)
			{
				cur=a[i][n];
				a[i][n]=pre;
				pre=cur;
			}
			n++;
		}
	}
	printf("New Matrix :\n");
	for(i=0;i<r+m;i++)
	{
		for(j=0;j<c+n;j++)
			printf("%2d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
