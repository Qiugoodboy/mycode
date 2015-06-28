#include"flight.h"
#include"print.h"
int flag=0;
void flight_add(flight_p *d)
{
	int num;
	printf(RED"*****功能选择*****\n"NONE);
	printf(BLUE"*** 0-文件加载 ***\n"NONE);
	printf(BLUE"*** 1-手动录入 ***\n"NONE);
	printf(RED"*********请选择:"NONE);
	scanf("%d",&num);
	getchar();
	switch(num)
	{
	case 0:load_message(d);break;
	case 1:head_message(d);break;
	default:break;
	}
}
void head_message(flight_p *d)
{
	flight_p p,new;
	int i;
	char ch,snbuf[10]={},sobuf[10]={};
	if(0==flag)
	{
		(*d)=(flight_p)malloc(sizeof(flight_t));
		if(NULL==*d)
		{
			printf("malloc error\n");
			exit(-1);
		}
		printf(RED"请依次输入以下数据:\n"NONE);
		printf(RED"航班号 起点站 终点站 班期 机型 起飞时间 到达时间 票价\n"NONE);
		scanf(GREEN"%s%s%s%s%s%s%s%d"NONE,(*d)->number,(*d)->staddress,(*d)->arraddress,\
				(*d)->date,(*d)->type,(*d)->stime,(*d)->atime,&(*d)->value);
		getchar();
		(*d)->front=(*d);
		(*d)->next=(*d);
		flag=1;
		printf(RED"是否继续输入(Y/N)"NONE);
label1:
		scanf("%c",&ch);
		getchar();
		if(ch=='N')
			return ;
		else if (ch!='N'&&ch!='Y')
		{
			printf(RED"请正确输入Y/N"NONE);
			goto label1;
		}
	}
	p=(*d);

	while(1)
	{
		new=(flight_p)malloc(sizeof(flight_t));
		if(NULL==new)
		{
			printf("malloc error\n");
			exit(-1);
		}
		printf(RED"请依次输入以下数据:\n"NONE);
		printf(RED"航班号\t起点站\t终点站\t班期\t机型\t起飞时间\t\t到达时间\t\t票价\n"NONE);
		scanf("%s\t%s\t%s\t%s\t%s\t%s\t%s%d",new->number,new->staddress,new->arraddress,\
				new->date,new->type,new->stime,new->atime,&new->value);
		getchar();
		snbuf[0]=new->stime[0];
		snbuf[1]=new->stime[2];
		snbuf[2]=new->stime[3];
		sobuf[0]=p->stime[0];
		sobuf[1]=p->stime[2];
		sobuf[2]=p->stime[3];
		if(atoi(snbuf)>atoi(sobuf))
		{
			while(atoi(snbuf)>atoi(sobuf)&&p->next!=(*d))
			{
				p=p->next;
				sobuf[0]=p->stime[0];
				sobuf[1]=p->stime[2];
				sobuf[2]=p->stime[3];
			}
				if(atoi(snbuf)>atoi(sobuf)&&p->next==(*d))
				{
					new->next=p->next;
					new->front=p;
					p->next=new;
					new->next->front=new;
				}
				else
				{
					new->front=p->front;
					new->next=p;
					new->next->front=new;
					new->front->next=new;
				}
		}
		else
		{
			while(atoi(snbuf)<atoi(sobuf)&&p!=(*d))
			{
				p=p->front;
				sobuf[0]=p->stime[0];
				sobuf[1]=p->stime[2];
				sobuf[2]=p->stime[3];
			}
			if(atoi(snbuf)<atoi(sobuf)&&p==(*d))
			{
				new->front=p->front;
				new->next=p;
				new->next->front=new;
				new->front->next=new;
				(*d)=new;
			}
			else
			{
				new->next=p->next;
				new->front=p;
				p->next=new;
				new->next->front=new;
			}
		}
		printf(RED"是否继续输入(Y/N):"NONE);
label:
		scanf("%c",&ch);
		getchar();
		if('N'==ch)
			return ;
		else if(ch!='N'&&ch!='Y')
		{
			printf(RED"请正确输入Y/N:"NONE);
			goto label;
		}
	}
}
void flight_all_show(flight_p p)
{
	if(0==flag)
	{
		printf(RED"目前还没录入条目\n"NONE);
		return ;
	}
	flight_p f;
	f=p;
	printf(RED"******************************航**班**信**息*********************************\n"NONE);
	printf(RED"*航班号\t起点站\t终点站\t班期\t机型\t起飞时间\t到达时间\t票价*\n"NONE);
	while(f->next!=p)
	{
		printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,f->arraddress,f->date,\
				f->type,f->stime,f->atime,f->value);
		f=f->next;
	}
	printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,f->arraddress,f->date,\
			f->type,f->stime,f->atime,f->value);
	printf(RED"*****************************************************************************\n"NONE);
}
void flight_check(flight_p p)
{
	int num;
	char buf[20];
	if(0==flag)
	{
		printf(RED"目前还没录入条目\n"NONE);
		return ;
	}
	printf(RED"*************\n"NONE);
	printf(BLUE"* 1-航班号  *\n* 2-起点站  *\n* 3-终点站  *\n* 4-班期    *\n* 5-机型    *\n* 6-起飞时间*\
			\n* 7-到达时间*\n* 8-票价    *\n"NONE);
	printf(RED"*************\n"NONE);
	printf(RED"******请选择:"NONE);
label2:
	scanf("%d",&num);
	getchar();
	if(num<1||num>8)
	{
		printf(RED"请正确输入选项:"NONE);
		goto label2;
	}
	printf(RED"请输入查询信息:"NONE);
	scanf("%s",buf);
	getchar();
	flight_serach(p,num,buf);
}
void flight_serach(flight_p p,int num,char * buf)
{
	flight_p f;
	f=p;
	printf(RED"******************************查**询**信**息*********************************\n"NONE);
	printf(RED"*航班号\t起点站\t终点站\t班期\t机型\t起飞时间\t到达时间\t票价*\n"NONE);
	if(num==1)
	{
		while(f->next!=p)
		{
			if(strcmp(f->number,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->number,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==2)
	{
		while(f->next!=p)
		{
			if(strcmp(f->staddress,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->staddress,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==3)
	{
		while(f->next!=p)
		{
			if(strcmp(f->arraddress,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->arraddress,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==4)
	{
		while(f->next!=p)
		{
			if(strcmp(f->date,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->date,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==5)
	{
		while(f->next!=p)
		{
			if(strcmp(f->type,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->type,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==6)
	{
		while(f->next!=p)
		{
			if(strcmp(f->stime,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->stime,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if(num==7)
	{
		while(f->next!=p)
		{
			if(strcmp(f->atime,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(strcmp(f->number,buf)==0)
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	else if (num==8)
	{
		while(f->next!=p)
		{
			if(f->value==atoi(buf))
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
			f=f->next;
		}
			if(f->value==atoi(buf))
			{
			printf(GREEN"*%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%d  *\n"NONE,f->number,f->staddress,\
			f->arraddress,f->date,f->type,f->stime,f->atime,f->value);
			}
	}
	printf(RED"*****************************************************************************\n"NONE);
}

void load_message(flight_p *d)
{
	FILE * fp;
	char buf[10],snbuf[50],sobuf[50];
	flight_p new,p;
	if(NULL==(fp=fopen("message.txt","r")))
	{
		perror("fopen");
		exit(-1);
	}
	if(0==flag)
	{
		(*d)=(flight_p)malloc(sizeof(flight_t));
		if(NULL==*d)
		{
			printf("malloc error\n");
			exit(-1);
		}
		if(-1==fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",(*d)->number,(*d)->staddress\
				,(*d)->arraddress,(*d)->date,(*d)->type,(*d)->stime,(*d)->atime,buf))
		{
			perror("fscanf");
			exit(-1);
		}
		(*d)->value=atoi(buf);
		(*d)->front=(*d);
		(*d)->next=(*d);
		flag=1;
	}
	p=(*d);
	while(0==feof(fp))
	{
		new=(flight_p)malloc(sizeof(flight_t));
		if(NULL==new)
		{
			printf("malloc error\n");
			exit(0);
		}
		if(-1==fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",new->number,new->staddress\
				,new->arraddress,new->date,new->type,new->stime,new->atime,buf))
		{
			perror("fscanf");
			exit(-1);
		}
		new->value=atoi(buf);
		snbuf[0]=new->stime[0];
		snbuf[1]=new->stime[2];
		snbuf[2]=new->stime[3];
		sobuf[0]=p->stime[0];
		sobuf[1]=p->stime[2];
		sobuf[2]=p->stime[3];
		if(atoi(snbuf)>atoi(sobuf))
		{
			while(atoi(snbuf)>atoi(sobuf)&&p->next!=(*d))
			{
				p=p->next;
				sobuf[0]=p->stime[0];
				sobuf[1]=p->stime[2];
				sobuf[2]=p->stime[3];
			}
				if(atoi(snbuf)>atoi(sobuf)&&p->next==(*d))
				{
					new->next=p->next;
					new->front=p;
					p->next=new;
					new->next->front=new;
				}
				else
				{
					new->front=p->front;
					new->next=p;
					new->next->front=new;
					new->front->next=new;
				}
		}
		else
		{
			while(atoi(snbuf)<atoi(sobuf)&&p!=(*d))
			{
				p=p->front;
				sobuf[0]=p->stime[0];
				sobuf[1]=p->stime[2];
				sobuf[2]=p->stime[3];
			}
			if(atoi(snbuf)<atoi(sobuf)&&p==(*d))
			{
				new->front=p->front;
				new->next=p;
				new->next->front=new;
				new->front->next=new;
				(*d)=new;
			}
			else
			{
				new->next=p->next;
				new->front=p;
				p->next=new;
				new->next->front=new;
			}
	}
}
}








