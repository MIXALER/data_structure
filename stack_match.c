#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    char c;
    struct ListNode *next;
};
typedef struct ListNode Node;
struct stack
{
    int size;
    struct ListNode *head;
    char top;
};

typedef struct stack Stack;

Stack *create_stack(void)
{
    Stack *st = (Stack *) malloc(sizeof(Stack));
    st->size = 0;
    st->head = NULL;
    st->top = NULL;
    return st;
}

int empty(Stack *stack)
{
    return stack->size == 0;
}

char top(Stack *stack)
{
    return stack->top;
}

void push_stack(Stack *stack, char item)
{
    Node *new = (Node *) malloc(sizeof(Node));
    new->c = item;
    new->next = stack->head;
    stack->head = new;
    stack->size++;
    stack->top = item;
}

int pop_stack(Stack *stack)
{
    if (empty(stack))
        return -1;
    Node *torm = stack->head;
    int retval = stack->head->c;
    stack->head = stack->head->next;
    free(torm);
    stack->size--;
    if (stack->size)
        stack->top = stack->head->c;
    else
        stack->top = NULL;
    return retval;
}

int is_match(char *str, int n)
{
    Stack *st = create_stack();
    push_stack(st, str[0]);
    for (int i = 1; i < n; ++i)
    {
        if (str[i] == '(')
            push_stack(st, str[i]);
        else
        {
            if (st->top == '(')
                pop_stack(st);
            else
                return 0;
        }
    }
    if (empty(st))
        return 1;
    return 0;
}

int main()
{
    // 栈的括号匹配，todo 尝试用数组实现栈的入栈操作和出栈操作
    char *str = "((())";
    int ret = is_match(str, 5);
    printf("%d\n", ret);
    return 0;
}