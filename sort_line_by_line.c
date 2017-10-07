#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage :./a.out filename\n");
		return;
	}
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("File not present\n");
		return;
	}
	int i=0,j,c=0,line=0;
	char ch,**s,*temp;
	//find largest line size for allocating dynamic memmory
	while((ch=fgetc(fp))!=EOF)
	{
		i++;
		if(ch=='\n')
		{
			if(i>c)
				c=i;
			line++;
			i=0;
		} 
	} 
	rewind(fp);

	s=malloc(sizeof(char*)*line);
	temp=malloc(c+1);
	for(i=0;i<line;i++)
		s[i]=malloc(c+1);

	//store file contents to dynamic memory
	i=0;
	while(fgets(s[i++],c+1,fp));
	fclose(fp);

	//sorting by line size(ascending order)
	for(i=0;i<line-1;i++)   
		for(j=i+1;j<line;j++)
			if(strlen(s[i])>strlen(s[j]))
			{
				strcpy(temp,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],temp);
			}
	//erasing data in file and rewrite sorted contents
	fp=fopen(argv[1],"w");
	for(i=0;i<line;i++)
		fputs(s[i],fp);

	free(temp);
	free(s);
        printf("\nSucess\n");
	return 0;
}
