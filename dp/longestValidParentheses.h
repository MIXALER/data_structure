//
// Created by yuanh on 2021/5/9.
//

#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        vector<int> flag(s.length(), 0);
        for(int i =0; i<s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (st.empty())
                    flag[i] = 1;
                else
                    st.pop();
            }
        }
        while (!st.empty())
        {
            flag[st.top()] = 1;
            st.pop();
        }
        int len = 0, max = 0;
        for (int i = 0; i < flag.size(); ++i)
        {
            if (flag[i] == 0)
            {
                len++;
                if (len > max)
                    max = len;
            }
            else
                len = 0;
        }
        return max;
    }
};