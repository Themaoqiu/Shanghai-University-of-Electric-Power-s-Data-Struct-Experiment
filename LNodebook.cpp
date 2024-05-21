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
	printf("��ǰ��Ŀ%d��\n", *length);
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
int AddBook(LinkList* L, LNode** r, int n, int *length)
{
	printf("������ ���� �۸�\n");
	int i = 0;
	for (i = 0; i < n; i++)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));
		scanf("%s %s %f", p->data.num, p->data.name, &p->data.price);
		p->next = NULL;
		(*r)->next = p;
		(*r) = p;
		printf("%s��ӳɹ�\n", p->data.name);
		++*length;
	}
	return OK;
}
int ListInsert(LinkList* L, int *length)
{
	int i = 0;
	printf("����Ҫ����Ŀ�����λ��:\n");
	scanf("%d", &i);
	Book e;
	printf("������Ŀ��� ���� �۸�:\n");
	scanf("%s %s %f", &e.num, &e.name, &e.price);
	if (i < 1)
	{
		printf("�����λ�ò��Ϸ�������������!!!!!");
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
	printf("������ɾ����Ŀ�ı��:\n");
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
	printf("ɾ���ɹ�\n");
	return OK;
}
int PrintfBook(LinkList* L)
{
	LNode* i = (*L)->next;
	while (i != NULL)
	{
		printf("------------------------------------------------------\n");
		printf("��ţ�%s ������%s �۸�%f\n", i->data.num, i->data.name, i->data.price);
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
		printf("��������鱾����:\n");
		scanf("%d", &n);
		flag = AddBook(&(*L), &(*r), n, &*length);
		if (flag == 1)
		{
			h = welcom(&*length);
			flag = 0;
		}
		else
		{
			printf("ϵͳ���������²���!!!!!");
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
			printf("ϵͳ���������²���!!!!!");
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
			printf("ϵͳ���������²���!!!!!");
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
			printf("ϵͳ���������²���!!!!!");
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
	printf("*******��ӭʹ��BYDͼ�����ϵͳV0.2******\n");
	while (1)
	{
		int a = 5;
		a = menu(&L, &r, &length);
		if (a == -1)
			break;
	}
	return 0;
}