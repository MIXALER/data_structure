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
    static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (!preorder.size())
            return nullptr;
        else
        {
            TreeNode* root = new TreeNode(preorder[0]);
            int mid=0;
            while (inorder[mid] != preorder[0])
                mid++;
            vector<int> l_preorder(preorder.begin()+1, preorder.begin()+mid+1);
            vector<int> r_preorder(preorder.begin()+mid+1, preorder.end());
            vector<int> l_inorder(inorder.begin(), inorder.begin()+mid);
            vector<int> r_inorder(inorder.begin()+mid+1, inorder.end());
            root->left = buildTree(l_preorder, l_inorder);
            root->right = buildTree(r_preorder, r_inorder);
            return root;
        }
    }
};


