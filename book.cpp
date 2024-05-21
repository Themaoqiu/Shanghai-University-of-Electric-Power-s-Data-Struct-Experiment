#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 50
#define OK 1
#include <stdio.h>
#include <string.h>
typedef struct 
{
	char num[20];
	char name[20];
	int price;
}Book;
typedef struct
{
	Book data[MaxSize];
	int length;
}Sqlist;
int welcom(int length)
{
	int h = 0;
	printf("��ǰ��%d������\n", length);
	printf("**********��ѡ��Ҫ���еĲ���************\n");
	printf("**************1.���ͼ��****************\n");
	printf("**************2.ɾ��ͼ��****************\n");
	printf("**************3.����ͼ��****************\n");
	printf("**************4.ͼ���б�****************\n");
	printf("**************0.�˳�ϵͳ****************\n");
	printf("����������Ҫ���еĲ��������Ұ�Enter���룡\n");
	scanf("%d", &h);
	return h;
}
void InitBook(Sqlist* L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		L->data[i].price = 0;
	}
	L->length = 0;
}
bool InsertBook(Sqlist* L, int i, Book e)
{
	if (i < 1 || i > L->length + 1)
		return false;
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
	return true;
}
int AddBook(Sqlist* L, int length)
{
	printf("������ ���� �۸�\n");
	scanf("%s %s %d", L->data[length].num, L->data[length].name, &L->data[length].price);
	printf("%s��ӳɹ�\n", L->data[length].name);
	L->length++;
	return OK;
}
int PrintfBook(Sqlist *L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		printf("------------------------------------------------------\n");
		printf("��ţ�%s ������%s �۸�%d\n", L->data[i].num, L->data[i].name, L->data[i].price);
		printf("------------------------------------------------------\n");
	}
	return OK;
}
int DelBook(Sqlist* L, int length)
{
	char num[20];
	PrintfBook(L);
	if (L->length == 0)
	{
		printf("ϵͳ��ʲôҲû��Ŷ\n");
		return OK;
	}
	printf("����Ҫɾ����Ŀ�ı�Ų���Enterȷ��\n");
	scanf("%s", &num);
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if (i == length)
		{
			printf("����û���Ȿ�飬�������ô");
			break;
		}
		int j = 0;
		if (strcmp(num, L->data[i].num) == 0)
			for (j = i; j < length; j++)
				L->data[j - 1] = L->data[j];
		L->length--;
	}
	return OK;
}
int main()
{
	int h = 0, flag = 0;
	Sqlist L;
	InitBook(&L);
	printf("*******��ӭʹ��BYDͼ�����ϵͳV0.1******\n");
	h = welcom(L.length);
	while (1)
	{
		
		if (h == 1)
		{
			flag = AddBook(&L, L.length);
			if (flag == 1)
				h = welcom(L.length);
			flag = 0;
		}
		if (h == 2)
		{
			flag = DelBook(&L, L.length);
			if (flag == 1)
				h = welcom(L.length);
			flag = 0;

		}
		if (h == 3)
		{
			PrintfBook(&L);
			int i = 0;
			printf("��������λ��\n");
			scanf("%d", &i);
			Book I;
			printf("���������Ŀ�ı�� ���� �۸�\n");
			scanf("%s %s %d", I.num, I.name, &I.price);
			flag = InsertBook(&L, i, I);
			if (flag == 1)
			{
				printf("����ɹ���\n");
				h = welcom(L.length);
			}
			flag = 0;
		}
		if (h == 4)
		{
			flag = PrintfBook(&L);
			if (flag == 1)
				h = welcom(L.length);
			flag = 0;

		}
		if (h == 0)
			break;
	}
	return 0;
}
