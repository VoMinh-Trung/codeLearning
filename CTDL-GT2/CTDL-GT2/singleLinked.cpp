#include <stdio.h>


struct node
{
	int data;//data 
	struct node* pNext;//pointer
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
NODE* khoiTaoNODE()
{

}

void main() 
{

}