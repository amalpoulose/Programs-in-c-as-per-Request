/* Program to reverse digits in a string
By Amal Poulose 9446047003      amalpoulose1995@gmail.com*/
#include<stdio.h>
char *My_strstr(const char * , const char *); 
int main(void)
{
	char str[100],sub[100];
        printf("\n---------------------------------------------------------\n");
	printf("enter the string  :");
	scanf("%[^\n]",str);
        printf("Enter the substring : ");
	scanf(" %[^\n]",sub);
        printf("\n---------------------------------------------------------\n");
        printf("String entered is   :  %s",str); 
        printf("\nString entered is   :  %s",sub); 
        printf("\n---------------------------------------------------------\n");
        char *p=My_strstr(str,sub);
        if(p)
          printf("The sub string found at    :%p  %s \n",p,p);
        else
          printf("The sub string not found\n" );
        printf("\n---------------------------------------------------------\n");
	return(0);
}

       
char *My_strstr(const char *str , const char *sub) 
{
       int start,end,i,j;
	for(start=-1,end=0;str[end];end++)
	{ if(str[end]!=sub[0])
		continue;
		start=end;
		for(i=start,j=0;sub[j];i++,j++)
			if(str[i]!=sub[j])
				break;
                if(!sub[j])
                     break;
                else
                   start=-1;
	}
        if(start+1)
           return((char*)str+start);
        else
           return(0);
}
