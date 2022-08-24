#include <stdio.h>

struct node 
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;

struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void initLIST(LIST &l) 
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *initNODE(int x) 
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
}


void main() 
{

}