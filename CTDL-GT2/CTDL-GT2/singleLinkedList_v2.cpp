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
	p->data = x;
	p->pNext = NULL;
	return p;
}

void addHEAD(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = NULL;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTAIL(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = NULL;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

//export list
void exportList(LIST l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		printf_s("%d  ", k->data);
	}
}

void MENU()
{
	int option;
	bool breakWhile = 1;
	while (breakWhile)
	{
		printf_s("\n\n--------- MENU ---------");
		printf_s("\n\n--------- 0.EXIT ---------");
		printf_s("\n\n--------- 1.INPUT VALUE ---------");
		printf_s("\n\n--------- 2.EPORT ---------");
		printf_s("\n\n--------- END ---------");

		printf_s("\nInput your select: ");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("\nNhap gia tri so nguyen");
				break;
			}
			case 2:
			{
				printf_s("\nXuat mang lien ket");
				break;
			}
			case 0:
			{
				printf_s("\nEXIT");
				breakWhile = 0;
				break;
			}
		}
	}
}

void main() 
{
	MENU();
}