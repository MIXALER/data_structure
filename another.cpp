//
// Created by yuanh on 2021/3/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0),  left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};
using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while (!q1.empty() || !q2.empty())
        {
            vector<int> i;
            while(!q1.empty())
            {
                TreeNode *temp = q1.front();
                q1.pop();
                i.push_back(temp->val);
                if(temp->left)
                {
                    q2.push(temp->left);
                }
                if(temp->right)
                {
                    q2.push(temp->right);
                }
            }
            if(!i.empty())
            {
                result.push_back(i);
            }
            i.clear();
            while(!q2.empty())
            {
                TreeNode *temp = q2.front();
                q2.pop();
                i.push_back(temp->val);
                if(temp->left)
                {
                    q1.push(temp->left);
                }
                if(temp->right)
                {
                    q1.push(temp->right);
                }
            }
            if(!i.empty())
                result.push_back(i);
            i.clear();
        }
        return result;
    }
    vector<int> quick_sort(vector<int> arr)
    {
        if(arr.size() == 1)
            return arr;
        r_quick_sort(arr, 0, arr.size()-1);
    }
    void r_quick_sort(vector<int>& arr, int low, int high)
    {
        if(low>=high)
            return;
        int mid_value = arr[high];
        int last_position = low-1;
        for(int i=low; i<high-1; i++)
        {
            if(arr[i] <= mid_value)
            {
                last_position++;
                swap(arr[last_position], arr[i] );
            }
        }
        swap(arr[++last_position], arr[high]);
        r_quick_sort(arr, low, last_position-1);
        r_quick_sort(arr, last_position+1, high);
    }
    bool is_reverse(string str)
    {
        int i=0; int j = str.size();
        if(str.empty())
            return true;
        while(i<j)
        {
            if (str[i] == ' ' && i<j)
            {
                i++;
                continue;
            }
            while(str[j] == ' ' && i<j)
            {
                j--;
                continue;
            }
            if((str[i] >='a' && str[i] <='z') ? (str[i] == str[j] || str[i] == str[j] -32) : str[i]== str[j])
            {
                i++;
                j--;
            }
        }
    }
    int evalRPN(vector<string>& tokens) {
        // write code here
        //如果是数字的话，压入栈中，如果是运算符，就从栈顶取两个数字计算，并将结果压入栈中。
        int ans;
        stack<int> st;
        if(tokens.size() <= 3)
            return 0;
        st.push(std::atoi(tokens[0].c_str()));
        st.push(std::atoi(tokens[1].c_str()));
        int temp_num1=0, temp_num2=0, temp_res=0;

        for(int i=2; i<tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                temp_num1 = st.top();
                st.pop();
                temp_num2 = st.top();
                st.pop();
                temp_res = temp_num1+temp_num2;
                st.push(temp_res);
            }
            if(tokens[i] == "-")
            {
                temp_num1 = st.top();
                st.pop();
                temp_num2 = st.top();
                st.pop();
                temp_res = temp_num1-temp_num2;
                st.push(temp_res);
            }
            if(tokens[i] == "*")
            {
                temp_num1 = st.top();
                st.pop();
                temp_num2 = st.top();
                st.pop();
                temp_res = temp_num1*temp_num2;
                st.push(temp_res);
            }
            if(tokens[i] == "/")
            {
                temp_num1 = st.top();
                st.pop();
                temp_num2 = st.top();
                st.pop();
                temp_res = temp_num1/temp_num2;
                st.push(temp_res);
            }
            st.push(std::atoi(tokens[i].c_str()));
        }
        ans = st.top();
        return ans;
    }

    vector<vector<int>>


};


int main()
{
    string s;
//    cin>> s;
//    string a;
//    cin>>a;
//    map<char, int> s_map;
//    int i=1;
//    for(auto c: s){
//        s_map[c] = i++;
//    }
//    vector<int> a_int;
//    for(auto c:a)
//    {
//        a_int.push_back(s_map[c]);
//    }
//    if(a_int.size()==1)
//        return a_int[0];
//    int flag=0;
//    for(int j=1; j<a_int.size()-1; j++)
//    {
//        if(a_int[j] > a[j-1])
//        {
//            continue;
//        }
//        if(a_int[j] <=a_int[j-1])
//        {
//            flag++;
//        }
//    }
//
//    cout<<flag*s.size()+a_int[a_int.size()-1]-a.size()<<endl;
    int ans = abs(-2);
    cout << ans;
}

