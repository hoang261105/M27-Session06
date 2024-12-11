#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

// Con tro top cua ngan xep
Node* top = NULL;

// Kiem tra ngan xep co rong hay khong
int isEmpty(){
	if(top == NULL){
		return 1;
	}
	return 0;
}

// Them phan tu
void push(int value){
	// Cap phat bo nho
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

// Xoa phan tu
void pop(){
	if(isEmpty() == 1){
		printf("Ngan xep rong!");
		return;
	}
	Node* temp = top;
	top = top->next;
	free(temp);
	printf("Lay ra khoi ngan xep thanh cong\n");
}
int peek(){
	if(isEmpty() == 1){
		printf("Ngan xep rong!");
		return -2;
	}
	return top->data;
}

void printStack() {
    if (isEmpty()) {
        printf("Ngan xep rong!\n");
        return;
    }
    Node* temp = top;
    printf("Danh sach phan tu trong ngan xep:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
	int value;

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
				push(value);
				break;
			case 2:
				printStack();
				break;
			case 3:
				pop();
				break;
			case 4:
				printf("%d\n", peek());
				break;
			case 0:
				exit(0);
			default:
				printf("Vui long chon lai!");
		}
	}while(1==1);
	return 0;
}
