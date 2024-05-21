#define _CRT_SECURE_NO_WARNINGS
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct SNode
{
	char data;
	struct SNode* next;
}*LinkStack,SNode;
int InitStack(LinkStack* S)
{
	S = NULL;
	return OK;
}
bool StackEmpty(int *length)
{
	if (*length == 0)
		return true;
	else
		return false;
}
int Push(LinkStack* S, char e, int *length)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL)
		return OVERFLOW;
	p->data = e;
	p->next = *S;
	*S = p;
	++*length;
	return OK;
}
int pop(LinkStack* S, char* e, int* length)
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	if (S == NULL)
		return ERROR;
	*e = (*S)->data;
	p = *S;
	*S = (*S)->next;
	free(p);
	--*length;
	if (*length == 0)
		S == NULL;
	return OK;
}
int GetTop(LinkStack S, char* x)
{
	if (S == NULL)
		return ERROR;
	*x = S->data;
	return OK;
}
int Match(LinkStack* S, int* length)
{
	InitStack(&*S);
	int flag = 1;
	char x;
	char e;
	cin >> e;
	while (e != '#' && flag != 0)
	{
		if (e == '(' || e == '[')
			Push(&*S, e, &*length);
		else if (e == ')')
		{
			GetTop(*S, &x);
			if (StackEmpty(&*length) == 0 && x == '(')
			{
				pop(&*S, &x, &*length);
				flag = 1;
			}
			else
				flag = 0;//非法
		}
		else if (e == ']')
		{
			GetTop(*S, &x);
			if (StackEmpty(&*length) == 0 && x == '[')
			{
				pop(&*S, &x, &*length);
				flag = 1;
			}
			else 
				flag = 0;
		}
		cin >> e;
	}
	if (StackEmpty(&*length) != 0 && flag != 0)
		return OK;
	else
		return ERROR;
}
int main()
{
	LinkStack S;
	int length = 0;
	printf("输入待匹配的表达式，以‘#’结尾：");
	int flag = Match(&S, &length);
	if (flag == OK)
		printf("匹配成功!!!!!");
	else
		printf("md，匹配失败");
	return 0;
}