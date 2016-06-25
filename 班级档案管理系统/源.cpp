#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10			//����������ݵĴ�С
struct student		//����ṹ��
{
	char name[10];		//����
	char no[10];			//ѧ��
	char sex;				//�Ա�
	int age;					//����
	char bnote[100];	//��ע
};
void print()//��ӡ������Ϣ
{
	printf("a.ѧ��������Ϣ¼��\n");
	printf("b.ѧ��������Ϣ��ʾ \n");
	printf("c.ѧ��������Ϣ����\n");
	printf("d.ѧ��������Ϣɾ�� \n"); 
	printf("e.ѧ��������Ϣ�޸� \n"); 
	printf("f.ѧ��������Ϣ��ѯ \n"); 
	printf("q.�˳�ѧ����Ϣϵͳ \n");
}
bool Check(char pass[6])//������֤
{
	FILE *fp;
	char ch;
	char a[7]={" "};
	int i = 0;
	if ((fp=fopen("c:\\password.txt","r"))==NULL) {
		printf("���ļ�ʧ��!\n");
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
		printf("�������\n");
		return false;
	}
	fclose(fp);
}
void GetInfo(struct student *arr,int n)//ѧ��������Ϣ¼��
{
	for (int i = 0;i<n;i++)
	{
		printf("����ѧ���Ļ�����Ϣ:\n  ����		ѧ�� �Ա�	����		��ע\n");
		scanf("%s %s %c %d %s",arr[i].name,arr[i].no,&arr[i].sex,&arr[i].age,arr[i].bnote);
	}
}
void Display(struct student* arr,int n)//ѧ��������Ϣ��ʾ
{
	printf("ѧ����Ϣ:����	ѧ��	�Ա�	����	��ע\n");
	for (int i = 0;i<n;i++){
		printf("%15s%15s%15c%15d%15s\n",arr[i].name,arr[i].no,arr[i].sex,arr[i].age,arr[i].bnote);
	}
}
void Save(struct student* arr,int n)//ѧ��������Ϣ���棬������c:\\student.txt
{
	FILE * fp;
	fp= fopen("c:\\student.txt","w+");
	if (fp == NULL)
	{
		printf("�ļ�������!\n");
		exit(0);
	}
	fwrite(arr,sizeof(struct student)*n,n,fp);
	fclose(fp);
}
void Modfiy(struct student* arr,int n)//ѧ��������Ϣ�޸�
{
	char number[10];
	bool flag=false;
	char pass[6];
	printf("����������:\n");
	scanf("%s",pass);
	if (Check(pass))
	{
		printf("�޸�ѧ����Ϣ:\n");
		printf("������ѧ��:\n");
		scanf("%s",number);
		for (int i =0;i<n;i++)
		{
			if (!strcmp(number,arr[i].no))
			{
				printf(" ����	ѧ��	�Ա�	����	��ע\n");
				printf("%12s%12s%12c%12d%12s\n",arr[i].name,arr[i].no,
					arr[i].sex,arr[i].age,arr[i].bnote);
				printf("please input information:\n");
				scanf("%s%s%c%d%s",arr[i].name,arr[i].no,&arr[i].sex,&arr[i].age,arr[i].bnote); Save(arr,n);
				flag = true;
			}
		}
		if (flag == false)
		{
			printf("��ѧ��������!:\n");
		}
	}
}
void Delete(struct student* arr,int n)//ѧ��������Ϣɾ��
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
		printf("��ѧ��������!:\n");
	}
}
void Search(struct student* arr,int n)
{
	int temp,i;
	bool flag=false;
	printf("---------------1.ͨ��ѧ�Ų�ѯ-------------\n"); 
	printf("---------------2.ͨ��������ѯ-----------\n"); 
	printf("---------------3.ͨ���Ա��ѯ------------\n");
	printf("---------------4.ͨ�������ѯ------------\n");
	printf("---------------5.�˳�,press 5 ------------\n"); 
	scanf("%d",&temp);
	switch (temp)
	{
	case 1://����ѧ�Ų�ѯ
		{
			char num[10];
			printf("������ѧ��:\n");
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
				printf("��ѧ��������.\n");
			}
		}
		break;
	case 2://�������ֲ�ѯ
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
				printf("��ѧ��������.\n");
			}
		}
		break;
	case 3://�����Ա��ѯ
		{
			char ch;
			printf("�������Ա�:\n");
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
				printf("��ѧ��������.\n");
			}
		}
		break;
	case 4://���������ѯ
		{
			char num_age;
			printf("����������:\n");
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
				printf("��ѧ��������.\n");
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
	printf("����������:\n");
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
			printf("��ѡ��:\n");
			scanf("%c",&select); }
	}
}