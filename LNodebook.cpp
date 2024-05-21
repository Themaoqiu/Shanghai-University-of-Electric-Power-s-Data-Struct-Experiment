#define _CRT_SECURE_NO_WARNINGS
#define OK 1
#define ERROR 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char num[20];
	char name[20];
	float price;
}Book;
typedef struct LNode
{
	Book data;
	struct LNode* next;
}LNode,*LinkList;
LNode *InitList(LinkList* L)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));;
	if (p == NULL)
		return ERROR;
	if (p != NULL)
	{
		p->next = NULL;
		return p;
	}
}
int welcom(int *length)
{
	int h = 0;
	printf("当前书目%d本\n", *length);
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
int AddBook(LinkList* L, LNode** r, int n, int *length)
{
	printf("输入编号 书名 价格：\n");
	int i = 0;
	for (i = 0; i < n; i++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));
		scanf("%s %s %f", p->data.num, p->data.name, &p->data.price);
		p->next = NULL;
		(*r)->next = p;
		(*r) = p;
		printf("%s添加成功\n", p->data.name);
		++*length;
	}
	return OK;
}
int ListInsert(LinkList* L, int *length)
{
	int i = 0;
	printf("输入要将书目插入的位置:\n");
	scanf("%d", &i);
	Book e;
	printf("输入书目编号 名称 价格:\n");
	scanf("%s %s %f", &e.num, &e.name, &e.price);
	if (i < 1)
	{
		printf("输入的位置不合法，请重新输入!!!!!");
		return ERROR;
	}
	LNode* p;
	int j = 0;
	p = *L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	++*length;
	return OK;
}
int ListDel(LinkList* L, int *length)
{
	char i[20];
	printf("输入所删除书目的编号:\n");
	scanf("%s", &i);
	LNode* p1;
	int j = 0, k = 0;
	p1 = *L;
	LNode* p2;
	p2 = *L;
	while (p1 != NULL && j < *length - 1)
	{
		if (strcmp(p1->data.num, i) == 0)
		{
			break;
		}
		else
		{
			p1 = p1->next;
			j++;
		}
	}
	while (p2 != NULL && k < *length - 1)
	{
		if (p2->next == p1)
		{
			break;
		}
		else
		{
			p2 = p2->next;
			k++;
		}
	}
	if (p2 == NULL)
		return ERROR;
	LNode* s = p2->next;
	p2->next = s->next;
	free(s);
	--*length;
	printf("删除成功\n");
	return OK;
}
int PrintfBook(LinkList* L)
{
	LNode* i = (*L)->next;
	while (i != NULL)
	{
		printf("------------------------------------------------------\n");
		printf("编号：%s 书名：%s 价格：%f\n", i->data.num, i->data.name, i->data.price);
		printf("------------------------------------------------------\n");
		i = i->next;
	}
	return OK;
}
int menu(LinkList *L, LNode **r, int *length)
{
	int h = 0, flag = 0;
	h = welcom(&*length);
	if (h == 1)
	{
		int n = 0;
		printf("输入添加书本数量:\n");
		scanf("%d", &n);
		flag = AddBook(&(*L), &(*r), n, &*length);
		if (flag == 1)
		{
			h = welcom(&*length);
			flag = 0;
		}
		else
		{
			printf("系统错误，请重新操作!!!!!");
			return ERROR;
		}
	}
	if (h == 2)
	{
		flag = ListDel(&(*L), &*length);
		if (flag == 1)
		{
			h = welcom(&*length);
			flag = 0;
		}
		else
		{
			printf("系统错误，请重新操作!!!!!");
			return ERROR;
		}
	}
	if (h == 3)
	{
		int i = 0;
		flag = ListInsert(&(*L), &*length);
		if (flag == 1)
		{
			h = welcom(&*length);
			flag = 0;
		}
		else
		{
			printf("系统错误，请重新操作!!!!!");
			return ERROR;
		}
	}
	if (h == 4)
	{
		flag = PrintfBook(&(*L));
		if (flag == 1)
		{
			h = welcom(&*length);
			flag = 0;
		}
		else
		{
			printf("系统错误，请重新操作!!!!!");
			return ERROR;
		}
	}
	if (h == 0)
		return -1;
}
int main()
{
	LNode* r;
	LinkList L;
	L = InitList(&L);
	r = L;
	int length = 0;
	printf("*******欢迎使用BYD图书管理系统V0.2******\n");
	while (1)
	{
		int a = 5;
		a = menu(&L, &r, &length);
		if (a == -1)
			break;
	}
	return 0;
}