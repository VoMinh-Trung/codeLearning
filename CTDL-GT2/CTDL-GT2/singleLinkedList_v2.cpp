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

void addTAIL(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
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

//add nodeP behind  nodeQ(nodeQ is node was in single linked list)
void addNodeP_behindNodeQ(LIST &l, NODE *p)
{
	int x;
	printf_s("Nhap gia tri node Q: ");
	scanf_s("%d", &x);
	NODE* q = initNODE(x);

	//if the condition is satisfied -> list have only one node
	//-> addTAIL
	if(q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		addTAIL(l, p);
	}
	//dont only one node
	else
	{
		//check start node to end node, cause find node Q
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data)
			{
				NODE* g = k->pNext;///g is intermediary node
				//step 1: create linked between P to G <-> pointer node P connect to node behind Q
				p->pNext = g;
				//step 2: create linked between pointer Q to node P <-> 
				k->pNext = p;
			}
		}
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
		printf_s("\n--------- 1.ENTER HEAD VALUE ---------");
		printf_s("\n--------- 2.ENTER TAIL VALUE ---------");
		printf_s("\n--------- 3.ADD NODE P BEHIND Q ---------");
		printf_s("\n--------- 10.EXPORT ---------");
		printf_s("\n--------- END ---------");

		printf_s("\nInput your select: ");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("\nEnter integer value node HEAD: ");
				int i;
				scanf_s("%d", &i);
				NODE *p = initNODE(i);
				addHEAD(l, p);
				break;
			}
			case 2:
			{
				printf_s("\nEnter integer value node TAIL: ");
				int i;
				scanf_s("%d", &i);
				NODE* p = initNODE(i);
				addTAIL(l, p);
				break;
			}
			case 3:
			{
				printf_s("\nEnter integer value node P: ");
				int i;
				scanf_s("%d", &i);
				NODE* p = initNODE(i);
				addNodeP_behindNodeQ(l, p);
				break;
			}



			case 10:
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