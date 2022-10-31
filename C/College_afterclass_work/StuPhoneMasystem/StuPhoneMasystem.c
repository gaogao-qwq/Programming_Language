# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student     //定义结构体
{
	//数据域
	char name[20];    //姓名
	char num[15];      //学号
	char sex[10];     //性别
	char from[20];    //籍贯
	char political[10];    //政治面貌
	char phone[15];      //手机号,
	char QQ[15];         //QQ号,
	char dorm[10];     //宿舍, 
	//指针域
	struct student *next; 
}stu;
stu *head;//定义头结点

void screen();	//软件介绍页面
void print();	   //主菜单
void input(stu *p1);	//数据输入（插入用）
stu *inputdata();	 //数据输入的函数
stu *lookdata(stu *p1); //输出数据的函数
void insert();			//插入数据
void deleted();			//删除数据函数
void find(stu *p2);		//通过学号查找数据
void update(stu *p2);	//通过学号查找并修改数据
void save(stu *p2);		//保存数据至外部文件

int main()//主函数
{
	int i;
	screen();
	while(1)
	{
		print();
		printf("请输入你的选择(1~9):");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
		case 1:
			inputdata();
			break;
		case 2:
			lookdata(head);
			break;
		case 3:
			insert();
			break;
		case 4:
			deleted();
			break;
		case 5:
			find(head);
			break;
		case 6:
			update(head);
			break;
		case 7:
			save(head);
			break;
		case 8:
			print();
			break;
		case 9:
			exit(1);
			break;
		}
	}
	system("cls");
}


void print()//主菜单
{
	system("cls");//清屏
	printf("\n\n\n");
	printf("      -----------------------------------------------------------\n\n");
	printf("      \t\t\t班级通讯录管理系统\n");
	printf("\n");
	printf("      \t\t1. 输入数据");
	printf("\t\t2. 显示数据\n");
	printf("      \t\t3. 插入数据");
	printf("\t\t4. 删除数据\n");
	printf("      \t\t5. 查看数据");
	printf("\t\t6. 修改数据\n");
	printf("      \t\t7. 保存数据");
	printf("\t\t8. 返回主菜单\n");
	printf("      -----------------------------------------------------------\n");
	printf("      \t\t退\t出\t请\t按\t9     \n");
	printf("      -----------------------------------------------------------\n\n");
}
 
 
void input(stu *p1)//数据输入（插入用）
{
	printf("姓名:");
	scanf("%s",p1->name);
	printf("学号:");
	scanf("%s",p1->num);
	printf("性别:");
	scanf("%s",p1->sex);
	printf("籍贯:");
	scanf("%s",p1->from);
	printf("政治面貌:");
	scanf("%s",p1->political);
	printf("手机号:");
	scanf("%s",p1->phone);
	printf("QQ号:");
	scanf("%s",p1->QQ);
	printf("宿舍:");
	scanf("%s",p1->dorm);
}
stu * inputdata()//数据输入的函数
{
	stu *p1,*p2;
	int i=1;
	p1=(stu *)malloc(sizeof(stu));
	if(p1!=NULL)
	{
		head=p1;
		printf("\n\t\t\t请输入数据\n");
		printf("ps：在姓名处输入“ok”代表输入数据结束\n");
		while(i)
		{
			printf("姓名:");
			scanf("%s",p1->name);
			if(strcmp(p1->name,"ok")==0)//退出
			{
				printf("\n输入完毕!\n");
				printf("========================================================================\n");
				i=0;
				p2->next=NULL;
				free(p1);
				p1=p2;
			}
			else//利用链表存储数据
			{
				printf("学号:");
				scanf("%s",p1->num);
				printf("性别:");
				scanf("%s",p1->sex);
				printf("籍贯:");
				scanf("%s",p1->from);
				printf("政治面貌:");
				scanf("%s",p1->political);
				printf("手机号:");
				scanf("%s",p1->phone);
				printf("QQ号:");
				scanf("%s",p1->QQ);
				printf("宿舍:");
				scanf("%s",p1->dorm);
				printf("=====================================\n");
				p2=p1;
				p1=(stu *)malloc(sizeof(stu));
				if(p1!=NULL)
				{
					p2->next=p1;
				}
			}
		}
		return(p1->next);
	}
}
stu * lookdata(stu *p1)//查看数据的函数
{
	printf("\n\t\t\t显示数据\n");
	printf("----------------------------------------------------------------------\n");
	while(p1!=NULL)
	{
		printf("姓名:%s\n",p1->name);
		printf("学号:%s\t",p1->num);
		printf("性别:%s\t",p1->sex);
		printf("籍贯:%s\t",p1->from);
		printf("政治面貌:%s\t",p1->political);
		printf("手机号:%s\t",p1->phone);
		printf("QQ号:%s\t",p1->QQ);
		printf("宿舍:%s\n",p1->dorm);
		printf("======================================================================\n");
	p1=p1->next;
	}
	system("pause");
	return p1;
}


void insert()//插入数据
{
    int i;
    char named[20];
    stu *p1,*p2,*p3;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));
    p3->next=NULL;
    printf("\n\t\t\t插入数据\n");
	printf("请输入插入者数据:\n");
	input(p3);//调用数据输入函数
	printf("\n插入选项\n");
	printf("1.首位置插入\t2.尾位置插入\n");
	printf("请输入你的选择:");
	scanf("%d",&i);
	switch(i)
	{
	case 1://头插
		{
			p3->next=p1;
			head=p3;
			break;
		}
		
	case 2://尾插
		{
			while(p1->next!=NULL)
			{
				p2=p1;
				p1=p1->next;
			}
			p1->next=p3;
			break;
		}
	}
	printf("插入成功!\n");
	system("pause");    
}
 
void deleted() //删除数据函数
{
	stu *p1,*p2;
	char Name[20];//想要删除的人的姓名
	printf("\n\t\t\t删除数据\n");
	printf("请输入要删除的姓名:");
	scanf("%s",Name);
	p1=head;
	//第一种情况，被删除结点为头结点，只需head指向第二个结点即可
	if(strcmp(Name,p1->name)==0)
	{
		head=p1->next;
		printf("删除成功!\n");
		system("pause");
		return;
	}
	//若不是头结点，循环遍历链表找出需删除的结点
	while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
	{
		p2=p1;
		p1=p1->next;
	}
	//判断节点是否存在在链表中
	if(p1==NULL)
	{
		printf("此人不存在!\n");
		system("pause");
		return;
	}
	//若存在判断被删除结点是否为尾结点
	if(p1->next!=NULL)
	{
		p1=p1->next;
		p2->next=p1;
		printf("删除成功!\n");
		system("pause");
		return;
	}
	else
	{
		p2->next=NULL;
		printf("删除成功!\n");
		system("pause");
		return;
	}
}

 
void find(stu *p2)//通过学号查看数据
{
	char name[20];
	int b=0;//flag
	printf("\n\t\t\t查看数据\n");
	printf("请输入您想查找人的学号:");
	scanf("%s",name);
	while(p2!=NULL)
	{
		if(strcmp(name,p2->num)==0)
		{
			printf("你要找到的数据\n");
			printf("姓名:%s\n",p2->name);
			printf("学号:%s\t",p2->num);
			printf("性别:%s\t",p2->sex);
			printf("籍贯:%s\t",p2->from);
			printf("政治面貌:%s\t",p2->political);
			printf("手机号:%s\t",p2->phone);
			printf("QQ号:%s\t",p2->QQ);
			printf("宿舍:%s\n",p2->dorm);
			b=1;
		}
		p2=p2->next;
	}
	if(b==0)
	{
		printf("\n您要查找的人不存在!\n");
	}
	system("pause");
}
 
 
void update(stu *p2)   //通过学号查找修改数据
{
	char num[20];
	int b=0,i;
	printf("\n\t\t\t修改数据\n");
	printf("请输入将要修改人的学号:");
	scanf("%s",num);
	while(p2!=NULL)
	{
		if(strcmp(num,p2->num)==0)
		{
			printf("该同学的基本信息\n");
			printf("姓名:%s\n",p2->name);
			printf("学号:%s\t",p2->num);
			printf("性别:%s\t",p2->sex);
			printf("籍贯:%s\t",p2->from);
			printf("政治面貌:%s\t",p2->political);
			printf("手机号:%s\t",p2->phone);
			printf("QQ号:%s\t",p2->QQ);
			printf("宿舍:%s\n",p2->dorm);
			printf("\n请选择要修改的信息\n");
			printf("\t1.姓名\t2.学号\t3.性别\t4.籍贯\n\t5.政治面貌\t6.手机号\t7.QQ\t8.宿舍\n");
			printf("\n您的选择是(1~8):");
			scanf("%d",&i);
			printf("请输入修改之后的内容\n");
			switch(i)
			{
			case 1:
				printf("姓名:");
				scanf("%s",p2->name);
				break;
			case 2:
				printf("学号:");
				scanf("%s",p2->num);
				break;
			case 3:
				printf("性别:");
				scanf("%s",p2->sex);
				break;
			case 4:
				printf("籍贯:");
				scanf("%s",p2->from);
				break;
			case 5:
				printf("政治面貌:");
				scanf("%s",p2->political);
				break;
			case 6:
				printf("手机号:");
				scanf("%s",p2->phone);
				break;
			case 7:
				printf("QQ:");
				scanf("%s",p2->QQ);
				break;
			case 8:
				printf("宿舍:");
				scanf("%d",p2->dorm);
				break;
			}
			printf("\n修改成功!\n");
			b=1;
		}
		p2=p2->next;
	}
	if(b==0)
	{
		printf("没有找到该人的资料!\n");
	}
	system("pause");
}
 
 
void save(stu *p2)//保存数据
{
	FILE *fp;
	char file[15];
	printf("\n\t\t\t保存数据\n");
    printf("输入文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("打开文件失败\n");
		system("pause");
		exit(0);
    }
	fprintf(fp, "姓名\t学号\t性别\t籍贯\t政治面貌\t手机号\tQQ号\t宿舍\n");
	while(p2!=NULL)
    {
		fprintf(fp, "%s\t", p2->name);
		fprintf(fp, "%s\t", p2->num);
		fprintf(fp, "%s\t", p2->sex);
		fprintf(fp, "%s\t", p2->from);
		fprintf(fp, "%s\t", p2->political);
		fprintf(fp, "%s\t", p2->phone);
		fprintf(fp, "%s\t", p2->QQ);
		fprintf(fp, "%s\n", p2->dorm);
		p2 = p2->next;
	}
    printf("\n保存成功!\n");;
    fclose(fp);
	system("pause");
}
 
 
void screen()  
{
	int i;
	char s[251]={"欢迎使用通讯录管理系统，\n\n\t\t\t 本系统用于通讯录管理\n\n\n\t\t\tWelcome to use address book\n\n\t\t\t    management system\n"};
		
	printf("\n======================= =========================================================\n");
	printf("\n\n\n\t\t\t");
	for (i = 0; s[i] != NULL; i++)
	{
		Sleep(30);//sleep函数，让程序挂起一段时间，此处用于控制输出s的内容的间隔时间，Windows下括号内时间为毫秒linux下位秒
		printf("%c",s[i]);
	}
	printf("================================================================================\n");
	system("pause");
}