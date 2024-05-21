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
	printf("当前有%d条数据\n", length);
	printf("**********请选择要进行的操作************\n");
	printf("**************1.添加图书****************\n");
	printf("**************2.删除图书****************\n");
	printf("**************3.插入图书****************\n");
	printf("**************4.图书列表****************\n");
	printf("**************0.退出系统****************\n");
	printf("请输入您需要进行的操作，并且按Enter进入！\n");
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
	printf("输入编号 书名 价格：\n");
	scanf("%s %s %d", L->data[length].num, L->data[length].name, &L->data[length].price);
	printf("%s添加成功\n", L->data[length].name);
	L->length++;
	return OK;
}
int PrintfBook(Sqlist *L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		printf("------------------------------------------------------\n");
		printf("编号：%s 书名：%s 价格：%d\n", L->data[i].num, L->data[i].name, L->data[i].price);
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
		printf("系统里什么也没有哦\n");
		return OK;
	}
	printf("输入要删除书目的编号并按Enter确认\n");
	scanf("%s", &num);
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if (i == length)
		{
			printf("根本没有这本书，你输的甚么");
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
	printf("*******欢迎使用BYD图书管理系统V0.1******\n");
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
			printf("输入插入的位置\n");
			scanf("%d", &i);
			Book I;
			printf("输入插入书目的编号 书名 价格\n");
			scanf("%s %s %d", I.num, I.name, &I.price);
			flag = InsertBook(&L, i, I);
			if (flag == 1)
			{
				printf("插入成功！\n");
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
