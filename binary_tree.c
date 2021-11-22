//
// Created by yuanh on 2021/9/11.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *create(int *in, int *pre, int size)
{
    // 中序序列和前序序列构建二叉树，可以尝试一下用后序加中序实现

    if (size == 0)
        return NULL;
    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->val = pre[0];
    int left_size = 0, right_size = 0;
    for (int i = 0; i < size; ++i)
    {
        if (in[i] != pre[0])
            left_size++;
        else
            break;
    }
    right_size = size - left_size - 1;
    root->left = create(in, pre + 1, left_size);
    root->right = create(in + left_size + 1, pre + left_size + 1, right_size);
    return root;
}

void in_order(TreeNode *root)
{
    if (root == NULL)
        return;
    in_order(root->left);

    printf("%d, ", root->val);

    in_order(root->right);

}

int main()
{
    int in[10] = {4, 2, 8, 5, 1, 6, 9, 3, 10, 7};
    int pre[10] = {1, 2, 4, 5, 8, 3, 6, 9, 7, 10};
    TreeNode *root = create(in, pre, 10);
    in_order(root);
    return 0;
}

