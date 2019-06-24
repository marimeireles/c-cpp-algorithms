#include <iostream>
#include <string>

bool stack_empty(int *stack, int *top)
{
    if (*top == 0)
        return true;
    else
        return false;
}

void push(int *stack, int x, int *top)
{
    *top += 1;
    stack[*top] = x;
}

void pop(int *stack, int *top)
{
    if (stack_empty(stack, top))
        printf("Underflow");
    else {
        printf("Element %d removed", stack[*top]);
        *top -= 1;
    }
}

int main(int argc, char const *argv[])
{
    int stack[1000];
    int top = 0;

    //test
    push(stack, 1, &top);
    push(stack, 2, &top);
    push(stack, 3, &top);

    pop(stack, &top);

    return 0;
}
