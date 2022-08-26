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
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

//add TAILnode linked list
void addTAIL(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		//printf_s("Danh sach rong");
		l.pHead = l.pTail = p;//head node = tail node = p 
	}
	else
	{
		l.pTail->pNext = p;//take pTail's pointer linked NODEp
		l.pTail = p;//update p is endNODE(pTail)
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

void MENU(LIST &l)
{
	int option;
	bool breakWhile = 1;
	while (breakWhile)
	{
		printf_s("\n\n--------- MENU ---------");
		printf_s("\n--------- 0.EXIT ---------");
		printf_s("\n--------- 1.INPUT VALUE ---------");
		printf_s("\n--------- 2.EXPORT ---------");
		printf_s("\n--------- END ---------");

		printf_s("\nInput your select: ");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("\nNhap gia tri so nguyen: ");
				int i;
				scanf_s("%d", &i);
				NODE *p = initNODE(i);
				addTAIL(l, p);
				break;
			}
			case 2:
			{
				printf_s("\nXuat mang lien ket: ");
				exportList(l);
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
	LIST l;
	initLIST(l);
	MENU(l);
}