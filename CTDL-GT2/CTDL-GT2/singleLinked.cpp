/*
* 1. struct node
*		data
*		pointer
* 2. struct list
*		pHead
*		pTail
* 3. initialize struction single linked list
*		pHead = pTail = NULL
* 4. initialize a node
*		pointer
* 5. add HEAD
* 6. add TAIL
*/


#include <stdio.h>

struct node
{
	int data;//a node's data 
	struct node* pNext;//pointer linked nodes
};
typedef struct node NODE;//replay name "struct node" to only one name "NODE"


//declare struction of single list
struct list
{
	NODE* pHead;//first node
	NODE* pTail;//end node
};
typedef struct list LIST;//replay name "struct list" to only one name "LIST"

//initialization single list
void khoiTao(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

//function initialization a node
NODE* khoiTaoNODE(int x)
{
	NODE* p = new NODE;//memory allocation for NODE p
	if (p == NULL) 
	{
		printf_s("Khong du bo nho cap phat");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;//return value for NODE p
}

//add HEADnode linked list
void addHEAD(LIST &l, NODE *p) 
{
	if (l.pHead == NULL)
	{
		//printf_s("Danh sach rong");
		l.pHead = l.pTail = p;//head node = tail node = p 
	}
	else
	{
		//take node's pointer want to add(p) linked to HEADnode
		p->pNext = l.pHead;
		//update HEADnode = p
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

//find max value
int findMaxValue(LIST l)
{
	int max = l.pHead->data;//for HEADnode is max
	//check max value from second node
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (max < k->data)
		{
			max = k->data;
		}
	}
	return max;
}


void main() 
{
	LIST l;
	khoiTao(l);//initialize
	int n;
	printf_s("\nNhap so luong node can them: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		printf_s("\nNhap gia tri so nguyen: ");
		scanf_s("%d", &x);
		NODE* p = khoiTaoNODE(x);//init node integer
		addTAIL(l, p);//add node p at head single linked list
	}
	printf_s("---DANH SACH LIEN KET---\n");
	exportList(l);
	printf_s("\n---MAX VALUE---\n");
	printf_s("\n%d", findMaxValue(l));
}