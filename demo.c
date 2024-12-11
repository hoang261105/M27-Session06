#include<stdio.h>
#include<stdlib.h>

#define MAX 5

// Cau truc ngan xep
typedef struct{
	int arr[MAX];	
	int top;
} Stack;

// Khoi tao stack rong
void initial(Stack* stack){
	stack->top = -1;
}

// Kiem tra cai stack co rong hay khong
int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

// Kiem tra ngan xep co bi day hay khong
int isFull(Stack* stack){
	if(stack->top >= MAX-1){
		return 1;
	}
	return 0;
}

void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("Ngan xep da day!");
		return;
	}
	stack->arr[++(stack->top)] = value;
}

// Xoa khoi ngan xep
void pop(Stack* stack){
	if(isEmpty(stack)){
		printf("Ngan xep rong!");
		return;
	}
	stack->arr[--(stack->top)];
}

int peek(Stack* stack){
	if(isEmpty(stack)){
		printf("Ngan xep rong!");
		return -1;
	}
	return stack->arr[stack->top];
}

void printStack(Stack* stack){
	for(int i=stack->top; i>=0; i--){
		printf("%d\n", stack->arr[i]);
	}
}

int main(){
	int value;
	Stack stack;
	initial(&stack);
	do{
		printf("---------------------MENU-------------------\n");
		printf("1. Them phan tu vao ngan xep\n");
		printf("2. In ra ngan xep\n");
		printf("3. Xoa khoi ngan xep\n");
		printf("4. Lay ra phan tu dau danh sach\n");
		printf("0. Thoat\n");
		printf("Moi ban chon: ");
		
		int choice;
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Nhap gia tri can them: ");
				scanf("%d", &value);
				push(&stack, value);
				break;
			case 2:
				printStack(&stack);
				break;
			case 3:
				pop(&stack);
				break;
			case 4:
				printf("%d\n", peek(&stack));
				break;
			case 0:
				exit(0);
			default:
				printf("Vui long chon lai!");
		}
	}while(1==1);
	return 0;
}
