#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
    char arr[MAX]; 
    int top;      
} Stack;

void initial(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep da day.\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return '\0'; 
    }
    return stack->arr[(stack->top)--];
}

int main() {
    char input[MAX];
    Stack stack;
    initial(&stack);

    printf("Nhap 1 chuoi: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; 

    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    char reversed[MAX];
    int index = 0;
    while (!isEmpty(&stack)) {
        reversed[index++] = pop(&stack);
    }
    reversed[index] = '\0'; 

    printf("Chuoi dao nguoc la: %s\n", reversed);

    return 0;
}

