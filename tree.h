//
// Created by yuanh on 2021/4/13.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#endif //LEETCODE_TREE_H

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};


class Tree
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


