#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct BiTNode
{
	char data;
	BiTNode* lchild;
	BiTNode* rchild;
}BiTNode, *BiTree;
typedef struct LinkNode 
{
	BiTNode data;
	struct LinkNode* next;
}LinkNode;
typedef struct
{
	LinkNode* front, * rear;
}LinkQueue;
void InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q->front->next = NULL;
}
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void EnQueue(LinkQueue* Q, BiTNode x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}
bool DeQueue(LinkQueue* Q, BiTNode* x)
{
	if (Q->front == Q->rear)
		return false;
	LinkNode* p = Q->front->next;//p指针指向出队节点
	*x = p->data;//x返回被删除的节点值
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;//若原队列只有一个节点，删除后队列设为空
	free(p);
	return true;
}
BiTNode* AddNode()
{
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
BiTNode* CreatTree(BiTree* T)
{
	char data;
	cin >> data;
	if (data == '#')
		return NULL;
	else
	{
		BiTree T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = data;
		printf("输入%c左节点数据：\n", T->data);
		T->lchild = CreatTree(&(T)->lchild);
		printf("输入%c右节点数据：\n", T->data);
		T->rchild = CreatTree(&(T)->rchild);
		return T;
	}
}
void visit(BiTree T)
{
	printf("%c", T->data);
}
void LevelOrder(BiTree T, LinkQueue* Q)
{
	InitQueue(&*Q);
	BiTree p = (BiTNode*)malloc(sizeof(BiTNode));
	EnQueue(&*Q, *T);
	while (IsEmpty(*Q) != true)
	{
		DeQueue(&*Q, &*p);
		visit(p);
		if (p->lchild != NULL)
			EnQueue(&*Q, *p->lchild);
		if (p->rchild != NULL)
			EnQueue(&*Q, *p->rchild);
	}
}
void PreOrder(BiTree T)//先序
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree T)//中序
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}
void PostOrder(BiTree T)//后序
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}
int TreeDeep(BiTree T)
{
	int deep = 0;
	if (T != NULL)
	{
		int leftdeep = TreeDeep(T->lchild);
		int rightdeep = TreeDeep(T->rchild);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1; 
	}
	return deep;
}
int LeafCount(BiTree T, int* count)
{
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
			(*count)++;
		LeafCount(T->lchild, &*count);
		LeafCount(T->rchild, &*count);
	}
	return *count;
}
int main()
{
	int count = 0, deep = 0;
	LinkQueue Q;
	BiTree T = CreatTree(&T);
	printf("层序遍历序列为：\n");
	LevelOrder(T, &Q);
	printf("\n先序遍历序列为：\n");
	PreOrder(T);
	printf("\n中序遍历序列为：\n");
	InOrder(T);
	printf("\n后序遍历序列为：\n");
	PostOrder(T);
	count = LeafCount(T, &count);
	printf("\n叶子结点个数为：%d", count);
	deep = TreeDeep(T);
	printf("\n树深度为：%d", deep);
	return 0;
}