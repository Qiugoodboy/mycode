#include"flight.h"
#include"print.h"
int main(int argc, const char *argv[])
{
	int num;
	char ch;
	flight_p p;
	while(1)
	{
	printf(RED"*****功能选择*****\n"NONE);
	printf(BLUE"*** 0-信息录入 ***\n"NONE);
	printf(BLUE"*** 1-信息查询 ***\n"NONE);
	printf(BLUE"*** 2-信息显示 ***\n"NONE);
	printf(RED"******************\n"NONE);
	printf(RED"*********请选择:"NONE);
	scanf("%d",&num);
	getchar();
	switch(num)
	{
	//信息录入
	case 0:flight_add(&p);break;
	//信息查询
	case 1:flight_check(p);break;
	//信息显示
	case 2:flight_all_show(p);break;
	default: break;
	}
	printf(RED"是否回到主选择窗口(Y/N):"NONE);
label1:
	scanf("%c",&ch);
	getchar();
	if('N'==ch)
		goto label;
	else if(ch!='N'&&ch!='Y')
	{
		printf(RED"请正确输入Y/N:"NONE);
		goto label1;
	}
	}
label:
	return 0;
}

