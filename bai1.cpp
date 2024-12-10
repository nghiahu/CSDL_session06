#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
	int array[MAX];
	int top;
} Stack;

void inital(Stack* stack){
	stack->top = -1;
}
int isFull(Stack* stack){
	if(stack->top >= MAX - 1){
		return 1;
	}
	return 0;
}
void push(Stack* stack,int value){
	if(isFull(stack) == 1){
		printf("Ngan xep da day, khong the them");
		return;
	}
	stack->array[++(stack->top)] = value;
}
void printStack(Stack* stack){
	for(int i = stack->top;i >= 0;i--){
		printf("%d\n",stack->array[i]);
	}
}
int main(){
	int value;
	Stack stack;
	inital(&stack);
	do{
		printf("\n================MENU==============\n");
		printf("1 .Them phan tu vao ngan xep\n");
		printf("2. In ra ngan xep\n");
		printf("0. Thoat\n");
		printf("Vui long chon: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0:
				exit(0);
			case 1:
				printf("Nhap vao gia tri can them: ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				printStack(&stack);
				break;
			default:
				printf("Vui long chon lai");
		}
	}while(1==1);
	return 0;
}

