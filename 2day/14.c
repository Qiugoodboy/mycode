#include<stdio.h>

int main(int argc, const char *argv[])
{
	int i=0,j=0,x=0,y=0;
	char text[100];
	printf("please enter to be analyzed(#to terminate)\n");
	while((text[i]=getchar())!='#')
	{
		i++;
		text[i]=getchar();
		if(text[i]=='#')
			break;
		i++;
	}
	text[i]='\0';
	for(j=0;j<i;j++)
	{
		if(text[j]=='\n')
		{
			x++;
		}
	}
	for(j=0;j<i;j++)
	{
		if(!((text[j]>64&&text[j]<91)||(text[j]>96&&text[j]<123)))
		{
			if((text[j-1]>64&&text[j-1]<91)||(text[j-1]>96&&text[j-1]<123))
			y++;
		}
	}
	if(text[i-1]!='\n')
		x++;
	printf("characters=%d,words=%d,lines=%d\n",i,y,x);
	return 0;
}
