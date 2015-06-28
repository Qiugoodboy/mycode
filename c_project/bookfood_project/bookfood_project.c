#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct menu
{
	int menu_num;
	char menu_name;
	char dist_name[3][10];
	int total_num;
	int meal_num;
	int menu_money;
}menu_t;
typedef struct disk_menu
{
	char setmeal_name;
	int shop_num;
	int meal_num;
}disk_menu_t;
int totalmoney=0;
menu_t *shop[3];

disk_menu_t * car[3];
char shop_name[3][15]={"真功夫","麦当劳","肯德基"};

void get_memery(menu_t **p,int size);
void assignment(menu_t ** p);
int print_shop(char p[3][15],int size);
int print_menu(menu_t ** p,int num);
int printf_meal(menu_t **p, int num1,int num2);

int main(int argc, const char *argv[])
{
	int num,num1;


	get_memery(shop,3);
	assignment(shop);
	num=print_shop(shop_name,3);
	num1=print_menu(shop,num);
	printf_meal(shop,num,num1);
	
	return 0;
}

void get_memery(menu_t **p,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
	p[i]=(menu_t *)malloc(15*sizeof(menu_t));
	if(p[i]==NULL)
	{
		printf("get_memery error!!\n");
		exit(0);
	}
	}
}

void assignment(menu_t ** p)
{
	p[0][0].total_num=3;
	p[0][1].menu_num=1;
	p[0][1].menu_name='A';
	p[0][1].menu_money=32;
	p[0][1].meal_num=3;
	strcpy(p[0][1].dist_name[0],"A1");
	strcpy(p[0][1].dist_name[1],"A2");
	strcpy(p[0][1].dist_name[2],"A3");
	p[0][2].menu_name='B';
	p[0][2].menu_num=2;
	p[0][2].menu_money=18;
	p[0][2].meal_num=3;
	strcpy(p[0][2].dist_name[0],"B1");
	strcpy(p[0][2].dist_name[1],"B2");
	strcpy(p[0][2].dist_name[2],"B3");
	p[0][3].menu_name='C';
	p[0][3].menu_num=3;
	p[0][3].menu_money=8;
	p[0][3].meal_num=3;
	strcpy(p[0][3].dist_name[0],"C1");
	strcpy(p[0][3].dist_name[1],"C2");
	strcpy(p[0][3].dist_name[2],"C3");
	
	
	p[1][0].total_num=3;
	p[1][1].menu_num=1;
	p[1][1].menu_name='A';
	p[1][1].menu_money=32;
	p[1][1].meal_num=3;
	strcpy(p[1][1].dist_name[0],"A1");
	strcpy(p[1][1].dist_name[1],"A2");
	strcpy(p[1][1].dist_name[2],"A3");
	p[1][2].menu_name='B';
	p[1][2].menu_num=2;
	p[1][2].menu_money=32;
	p[1][2].meal_num=3;
	strcpy(p[1][2].dist_name[0],"B1");
	strcpy(p[1][2].dist_name[1],"B2");
	strcpy(p[1][2].dist_name[2],"B3");
	p[1][3].menu_name='C';
	p[1][3].menu_num=3;
	p[1][3].menu_money=20;
	p[1][3].meal_num=3;
	strcpy(p[1][3].dist_name[0],"C1");
	strcpy(p[1][3].dist_name[1],"C2");
	strcpy(p[1][3].dist_name[2],"C3");

	p[2][0].total_num=3;
	p[2][1].menu_num=1;
	p[2][1].menu_name,'A';
	p[2][1].menu_money=32;
	p[2][1].meal_num=3;
	strcpy(p[2][1].dist_name[0],"A1");
	strcpy(p[2][1].dist_name[1],"A2");
	strcpy(p[2][1].dist_name[2],"A3");
	p[2][2].menu_name='B';
	p[2][2].menu_num=2;
	p[2][2].menu_money=15;
	p[2][2].meal_num=3;
	strcpy(p[2][2].dist_name[0],"B1");
	strcpy(p[2][2].dist_name[1],"B2");
	strcpy(p[2][2].dist_name[2],"B3");
	p[2][3].menu_name='C';
	p[2][3].menu_num=3;
	p[2][3].menu_money=12;
	p[2][3].meal_num=3;
	strcpy(p[2][3].dist_name[0],"C1");
	strcpy(p[2][3].dist_name[1],"C2");
	strcpy(p[2][3].dist_name[2],"C3");

}
int print_shop(char p[3][15],int size)
{
	int i,num;
	printf("*****点餐系统*****\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",i);
		printf("%s\n",p[i]);
	}
	printf("please select num:");
	fflush(stdout);
	scanf("%d",&num);
	return num;
}

int print_menu(menu_t ** p,int num)
{
	int i,total,ret;
	total=p[num][0].total_num;
	printf("****套餐列表****\n");
	for(i=1;i<=total;i++)
	{
		printf("%d\t",p[num][i].menu_num);
		printf("%d\t",p[num][i].menu_money);
		printf("%c\n",p[num][i].menu_name);
	}
	printf("请选择套餐:");
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}

int printf_meal(menu_t **p, int num1,int num2)
{
	int i;
	char tmp,tmp1,tmp2;
	static n=0;
	int value1,value2,value3;
	for(i=0;i<p[num1][num2].meal_num;i++)
	{
		printf("%s\n",p[num1][num2].dist_name[i]);
	}
	printf("是否加入购物?(Y/N)\n");
	fflush(stdout);
	getchar();
	scanf("%c",&tmp);
	if(tmp=='Y')
	{
		car[n]=(disk_menu_t *)malloc(sizeof(disk_menu_t));
		car[n]->setmeal_name=p[num1][num2].menu_name;
		car[n]->shop_num=num1;
		car[n]->meal_num=num2;
		totalmoney+=p[num1][num2].menu_money;
		printf("%c %d %d",car[n]->setmeal_name,num1,num2);
		n++;
		printf("成功加入购物车\n");
		printf("是否继续点餐(Y/N)\n");
		fflush(stdout);
		getchar();
		scanf("%c",&tmp1);
		if(tmp1=='Y')
		{
			goto label;
		}
		else if (tmp1=='N')
		{
			printf("一共%d元，谢谢惠顾！！\n",totalmoney);
			exit(-1);
		}
	}
	else if (tmp=='N')
	{
		printf("是否继续点餐?(Y/N)\n");
		fflush(stdout);
		getchar();
		scanf("%c",&tmp2);
		if(tmp2=='Y')
		{
			goto label;
		}
		else
		{
			printf("一共%d谢谢惠顾！！\n",totalmoney);
			exit(-1);
		}
	}
label:
	value1=print_shop(shop_name,3);
	value2=print_menu(shop,value1);
	printf_meal(shop,value1,value2);
	exit(-1);
	
}












