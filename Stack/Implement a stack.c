#include <stdio.h>

#define max_size 100

int stack[max_size];
int top = -1;

int pop();
void push(int data);

void printdata()
{
    while (top != -1)
    {
        printf("%d\n", pop());
    }
}

void push(int data)
{
    if (top == max_size - 1)
    {
        printf("Overflow stack !\n");
        return;
    }
    top = top + 1;
    stack[top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("stack is empty!\n");
        return -1;
    }
    int data;

    data = stack[top];
    top = top - 1;
    return data;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(3);

    printf("Elements in the stack are: ");
    printdata();
}
