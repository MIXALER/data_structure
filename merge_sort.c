#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
typedef struct node node;

void bubble(int *a, int n)
{
    // 冒泡排序
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[i])
            {
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

void quick_sort(int *a, int n)
{
    // 快速排序，todo!!
}

node *cut(node *l, int step)
{
    // 分割链表
    while (l && --step)
    {
        l = l->next;
        printf("%d, ", l->val);

    }
    if (!l)
        return NULL;
    node *next = l->next;
    l->next = NULL;

    return next;
}

node *merge(node *l1, node *l2)
{
    // 合并两个升序链表
    node *dummy = (node *) malloc(sizeof(node));
    dummy->val = 0;
    dummy->next = NULL;
    node *ptr = dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        } else
        {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
    }
    if (l1)
    {
        ptr->next = l1;
    }
    if (l2)
    {
        ptr->next = l2;
    }
    return dummy->next;
}

node *merge_sort(node *l, int n)
{
    // 归并排序
    node *dummy = (node *) malloc(sizeof(node));
    dummy->next = l;
    for (int step = 1; step < n; step *= 2)
    {
        node *cur = dummy->next;
        node *tail = dummy;
        while (cur)
        {
            node *left = cur;
            node *right = cut(left, step);
            cur = cut(right, step);
            tail->next = merge(left, right);
            while (tail->next)
                tail = tail->next;
        }
    }
    return dummy->next;
}


node *create_list(int *a, int n)
{
    // 尾插法构建单链表
    node *dummy = (node *) malloc(sizeof(node));
    dummy->val = 0;
    dummy->next = NULL;
    node *ptr = dummy;
    for (int i = 0; i < n; ++i)
    {
        node *tmp_node = (node *) malloc(sizeof(node));
        tmp_node->val = *(a + i);
        tmp_node->next = NULL;
        ptr->next = tmp_node;
        ptr = ptr->next;
    }
    return dummy->next;
}

void print_list(node *l)
{
    while (l != NULL)
    {
        printf("%d, ", l->val);
        l = l->next;
    }
    printf("\n");
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

}

int main(int argc, char **argv)
{
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    node *l = create_list(a, 10);
    bubble(a, 10);
//    print_array(a, 10);
    l = merge_sort(l, 10);
    print_list(l);
    return 0;
}
