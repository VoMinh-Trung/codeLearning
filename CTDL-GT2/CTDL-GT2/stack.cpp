#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 20

struct STACK {
	int top;
	char nodes[MAX];
};

void Initialize(STACK* stack) {
	stack->top = -1;
}

int Empty(STACK* stack) {
	if (stack->top == -1)
		return 1;
	return 0;
}

int Full(STACK *stack) {
	if (stack->top == MAX - 1)
		return 1;
	return 0;
}

void Push(STACK* stack, char x) {
	if (Full(stack)) {
		printf("Ngan xep day\n");
	}
	else
		stack->nodes[++stack->top] = x;
}

int Pop(STACK* stack) {
	if (Empty(stack)) {
		printf("Ngan xep rong\n");
	}
	else
		return (stack->nodes[stack->top--]);
}

char value_rand() {//random integer value from 0-9, then change to char value 
	//srand(time(NULL));
	int r = rand() % 9;
	char c = r + 48;
	return c;
}
void taoChuoiTuDong(char *chuoi, int max) {
	for (int i = 0; i < max; i++) {
		char c = value_rand();
		chuoi[i] = c;
		printf("%c", chuoi[i]);
	}
}

void daoNguocChuoi() {
	STACK stack;
	char chuoi[MAX];
	int i, len;
	Initialize(&stack);
	printf("\nNhap mot chuoi: \n");
	//gets_s(chuoi);//enter string you want lower MAX char
	taoChuoiTuDong(chuoi, MAX);
	len = strlen(chuoi);
	for (int i = 0; i < MAX; i++)
		Push(&stack, chuoi[i]);
	printf("\nin chuoi nguoc\n");
	while (!Empty(&stack))
		printf("%c", Pop(&stack));
}

void main() {
	daoNguocChuoi();

}