#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10			//定义测试数据的大小
struct student		//定义结构体
{
	char name[10];		//姓名
	char no[10];			//学号
	char sex;				//性别
	int age;					//年龄
	char bnote[100];	//备注
};
void print()//打印基本信息
{
	printf("a.学生基本信息录入\n");
	printf("b.学生基本信息显示 \n");
	printf("c.学生基本信息保存\n");
	printf("d.学生基本信息删除 \n"); 
	printf("e.学生基本信息修改 \n"); 
	printf("f.学生基本信息查询 \n"); 
	printf("q.退出学生信息系统 \n");
}
bool Check(char pass[6])//密码验证
{
	FILE *fp;
	char ch;
	char a[7]={" "};
	int i = 0;
	if ((fp=fopen("c:\\password.txt","r"))==NULL) {
		printf("打开文件失败!\n");
		exit(0);
	}
	ch=fgetc(fp);
	while (ch!=EOF&&i<6)
	{
		a[i] = ch;
		ch=fgetc(fp);
		i++;
	}
	a[6] = '\0';
	if (!strcmp(pass,a))
	{
		return true;
	}
	else
	{
		printf("密码错误\n");
		return false;
	}
	fclose(fp);
}
void GetInfo(struct student *arr,int n)//学生基本信息录入
{
	for (int i = 0;i<n;i++)
	{
		printf("输入学生的基本信息:\n  姓名		学号 性别	年龄		备注\n");
		scanf("%s %s %c %d %s",arr[i].name,arr[i].no,&arr[i].sex,&arr[i].age,arr[i].bnote);
	}
}
void Display(struct student* arr,int n)//学生基本信息显示
{
	printf("学生信息:姓名	学号	性别	年龄	备注\n");
	for (int i = 0;i<n;i++){
		printf("%15s%15s%15c%15d%15s\n",arr[i].name,arr[i].no,arr[i].sex,arr[i].age,arr[i].bnote);
	}
}
void Save(struct student* arr,int n)//学生基本信息保存，保存在c:\\student.txt
{
	FILE * fp;
	fp= fopen("c:\\student.txt","w+");
	if (fp == NULL)
	{
		printf("文件不存在!\n");
		exit(0);
	}
	fwrite(arr,sizeof(struct student)*n,n,fp);
	fclose(fp);
}
void Modfiy(struct student* arr,int n)//学生基本信息修改
{
	char number[10];
	bool flag=false;
	char pass[6];
	printf("请输入密码:\n");
	scanf("%s",pass);
	if (Check(pass))
	{
		printf("修改学生信息:\n");
		printf("请输入学号:\n");
		scanf("%s",number);
		for (int i =0;i<n;i++)
		{
			if (!strcmp(number,arr[i].no))
			{
				printf(" 姓名	学号	性别	年龄	备注\n");
				printf("%12s%12s%12c%12d%12s\n",arr[i].name,arr[i].no,
					arr[i].sex,arr[i].age,arr[i].bnote);
				printf("please input information:\n");
				scanf("%s%s%c%d%s",arr[i].name,arr[i].no,&arr[i].sex,&arr[i].age,arr[i].bnote); Save(arr,n);
				flag = true;
			}
		}
		if (flag == false)
		{
			printf("该学生不存在!:\n");
		}
	}
}
void Delete(struct student* arr,int n)//学生基本信息删除
{
	char number[10];
	bool flag=false;
	printf("Delete information:\n");
	printf("please input the no:\n");
	scanf("%s",number);
	for (int i =0;i<n;i++)
	{
		if (!strcmp(number,arr[i].no))
		{
			strcpy(arr[i].name," ");
			strcpy(arr[i].no," ");
			strcpy(arr[i].bnote," "); \
				arr[i].sex = ' ';
			arr[i].age = 0;
			Save(arr,n);
			flag = true;
		}
	}
	if (flag == true)
	{
		printf("该学生不存在!:\n");
	}
}
void Search(struct student* arr,int n)
{
	int temp,i;
	bool flag=false;
	printf("---------------1.通过学号查询-------------\n"); 
	printf("---------------2.通过姓名查询-----------\n"); 
	printf("---------------3.通过性别查询------------\n");
	printf("---------------4.通过年龄查询------------\n");
	printf("---------------5.退出,press 5 ------------\n"); 
	scanf("%d",&temp);
	switch (temp)
	{
	case 1://按照学号查询
		{
			char num[10];
			printf("请输入学号:\n");
			scanf("%s",num);
			for ( i =0;i<n;i++)
			{
				if (!strcmp(num,arr[i].no))
				{
					printf("%12s%12s%12c%12d%12s\n",arr[i].name,arr[i].no, arr[i].sex,arr[i].age,arr[i].bnote);
					flag = true;
				}
			}
			if (!flag)
			{
				printf("该学生不存在.\n");
			}
		}
		break;
	case 2://按照名字查询
		{
			char num[10];
			printf("please input name:\n");
			scanf("%s",num);
			for ( i =0;i<n;i++)
			{
				if (!strcmp(num,arr[i].name))
				{
					printf("%12s%12s%12c%12d%12s",arr[i].name,arr[i].no, arr[i].sex,arr[i].age,arr[i].bnote);
					flag = true;
				}
			}
			if (!flag)
			{
				printf("该学生不存在.\n");
			}
		}
		break;
	case 3://按照性别查询
		{
			char ch;
			printf("请输入性别:\n");
			scanf("%c",&ch);
			getchar();
			for ( i =0;i<n;i++)
			{
				if (ch == arr[i].sex)
				{
					printf("%12s%12s%12c%12d%12s\n",arr[i].name,arr[i].no, arr[i].sex,arr[i].age,arr[i].bnote);
					flag = true;
				}
			}
			if (!flag)
			{
				printf("该学生不存在.\n");
			}
		}
		break;
	case 4://按照年龄查询
		{
			char num_age;
			printf("请输入年龄:\n");
			scanf("%d",&num_age);
			for ( i =0;i<n;i++)
			{
				if (num_age == arr[i].age)
				{
					printf("%12s%12s%12c%12d%12s\n",arr[i].name,arr[i].no, arr[i].sex,arr[i].age,arr[i].bnote);
					flag = true;
				}
			}
			if (!flag)
			{
				printf("该学生不存在.\n");
			}
		}
		break;
	default:
		break;
	}
}
void main()
{
	struct student arr[N];
	char pass[6];
	printf("请输入密码:\n");
	scanf("%s",pass);
	if (Check(pass))
	{
		char select = 'a';
		print();
		scanf("%c",&select);
		while (('a'<select && select <'f') || select == 'q' ) {
			switch (select)
			{
			case 'a':
				GetInfo(arr,N);
				print();
				break;
			case 'b':
				Display(arr,N);
				print();
				break;
			case 'c':
				Save(arr,N);
				print();
				break;
			case 'd':
				Delete(arr,N);
				print();
				break;
			case 'e':
				Modfiy(arr,N);
				print();
				break;
			case 'f':
				Search(arr,N);
				print();
				break;
			default:
				break;
			}
			printf("请选择:\n");
			scanf("%c",&select); }
	}
}