#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
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
		printf("Ngan xep da day");
		return;
	}
	stack->arr[++(stack->top)] = value;
}

void printStack(Stack* stack){
	for(int i=stack->top; i>=0; i--){
		printf("%d\n", stack->arr[i]);
	}
}

int main(){
	int n;
	int value;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	Stack stack;
	initial(&stack);
	
	for(int i=0; i<n; i++){
		printf("arr[%d] = ", i);
		scanf("%d", &value);
		push(&stack, value);
	}
		
	printStack(&stack);
		
	return 0;
}
