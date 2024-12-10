#include <stdio.h>
#define MAX 100

typedef struct {
    int array[MAX];
    int top;
} Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep day, khong the them\n");
    } else {
        stack->array[++stack->top] = value;
    }
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return -1;
    } else {
        int value = stack->array[stack->top--];
        return value;
    }
}
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
    } else {
        printf("Cac phan tu trong ngan xep: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    int n, value, poppedValue;
    init(&stack);
    printf("Nhap so luong phan tu can thêm: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("So luong phan tu khong duoc vuot qua 100", MAX);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("[%d] = ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }
    display(&stack);
    poppedValue = pop(&stack);
    display(&stack);

    return 0;
}

