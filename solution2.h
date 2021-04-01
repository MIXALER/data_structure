#include <stack>
#include <string>
#include_next <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution{
public:
    string compress_me(string str) {
        // 字符串压缩算法，练习栈的使用。
        string ans;
        stack<char> st_symbol; //存放括号和压缩倍数
        stack<char> st_letter; //存放要还原的字符
        for(auto c:str)
        {
            if(c=='[' || (c>='0' && c<='9'))
                st_symbol.push(c);
            else if(!st_symbol.empty() && c!=']')
            {
                st_letter.push(c);
            } else if(c==']' && !st_symbol.empty())
            {
                string temp_letter;
                string mid_result_letter;
                string temp_num;
                while(st_letter.top()!='|')
                {
                    temp_letter.push_back(st_letter.top());
                    st_letter.pop();
                }
                reverse(temp_letter.begin(), temp_letter.end());
                st_letter.pop();
                while (st_symbol.top()!='[')
                {
                    temp_num.push_back(st_symbol.top());
                    st_symbol.pop();
                }
                st_symbol.pop();
                reverse(temp_num.begin(), temp_num.end());
                int t_time = stoi(temp_num);
                while (t_time>0)
                {
                    mid_result_letter += temp_letter;
                    t_time--;
                }
                for(auto letter:mid_result_letter)
                    st_letter.push(letter);
                mid_result_letter.clear();
                if(st_symbol.empty())
                {
                    while (!st_letter.empty())
                    {
                        mid_result_letter.push_back(st_letter.top());
                        st_letter.pop();
                    }
                    reverse(mid_result_letter.begin(), mid_result_letter.end());
                    for(auto letter: mid_result_letter)
                        ans.push_back(letter);
                    mid_result_letter.clear();
                }
            } else
                ans.push_back(c);
        }
        return ans;
    }
    string compress_2(string str) {
        // write code here
        string s=str;
        int i = 0;
        while(i < s.length()){
            if(s[i] == ']'){
                int j = i;//j用来向前寻找与]相匹配的 '['
                int k = 0;//k用来记录'|'所在位置
                while(s[j] != '['){
                    if(s[j] == '|')
                        k = j;
                    j--;
                }
                int len = stoi(s.substr(j+1,k-j));
                string s1 = s.substr(k+1,i - k - 1);
                string s2;
                for(int si = 0; si < len; si++){//将识别到的括号内容进行解码
                    s2 += s1;
                }
                s = s.replace(j,i-j+1,s2);
                i = j;//替换后i所指向的内容变化，从替换部分的头开始再寻找
            }

            i++;
        }
        return s;
    }
    string compress_3(string str) {
        string ans;
        vector<string> st;
        vector<int> count;
        string tmp="";
        int size=str.size();
        for(int i=0;i<size;){
            if(str[i]=='['){
                st.push_back(tmp);
                tmp="";
            }else if(str[i]==']'){
                string back=st.back();
                //cout<<back<<endl;
                st.pop_back();
                int num=count.back();
                count.pop_back();
                for(int j=0;j<num;j++) back+=tmp;
                //st.push_back(back);
                //cout<<back;
                tmp=back;
            }else if(str[i]>='0'&&str[i]<='9'){
                int j=i,num=0;
                while(str[j]>='0'&&str[j]<='9'&&j<size){
                    num=num*10+str[j]-'0';
                    j++;
                }
                count.push_back(num);
                i=j;
            }else{
                tmp+=str[i];
                //cout<<tmp<<endl;
            }
            i++;
        }
        return tmp;
        // write code here
    }
    string compressCore(int  num, string str) {
        string temp;
        for (int i = 0; i < num; ++i) {
            temp += str;
        }
        return temp;
    }
    string stringCut(string str, int start, int end) {
        string temp;
        if (str.size() < end || start > end)
            return temp;
        for (int i = start; i < end; ++i) {
            temp.push_back(str[i]);
        }
        return temp;
    }
    bool needcompress(string &str, int &start, int &end) {
        bool find = false;
        for (int i = 0; i < str.size(); ++i) {
            if (!find) {
                if (str[i] == '[') {
                    start = i;
                    find = true;
                }
            }
            else {
                if (str[i] == '[') {
                    start = i;
                }
                else if (str[i] == ']') {
                    end = i + 1;
                    return true;
                }

            }
        }
        return false;
    }
    string parse(string str) {
        cout << "parse:" << str << endl;
        string temp;
        int num = 0;
        int i = 0;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            ++i;
        }
        cout << "parse: num=" << num << endl;
        if (num == 0 || str[i] != '|')
            return temp;
        string temp2 = stringCut(str, i + 1, str.size());
        cout << "parse: temp2=" << temp2 << endl;

        for (int j = 0; j < num; ++j) {
            temp.append(temp2);
        }
        cout << "parse: temp=" << temp << endl;
        return temp;
    }
    string compress_4(string str) {
        // write code here
        int start, end;

        while (needcompress(str, start, end)) {
            cout << "start = " << start << "   end = " << end << endl;
            str = stringCut(str, 0, start) + parse(stringCut(str, start + 1, end - 1)) + stringCut(str, end, str.size());
        }
        return str;
    }
    string compress_5(string str) {
        // write code here
        int n=str.length();
        int idx=0;
        stack<char> stk;
        while(idx<n){
            if(str[idx]==']'){
                string s;
                while(stk.top()!='|'){
                    s.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                string num_s;
                while(stk.top()!='['){
                    num_s.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                reverse(num_s.begin(),num_s.end());
                //               reverse(s.begin(),s.end());
                int num=stoi(num_s);
                for(int i=0;i<num;++i){
                    for(int j=s.size()-1;j>=0;--j){
                        stk.push(s[j]);
                    }
                }
            }
            else{
                stk.push(str[idx]);
            }
            ++idx;
        }
        string res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string compress_6(string str) {
        // write code here
        int u = 0;
        return dfs(str, u, "");
    }
    string dfs(const string& s, int& u, string cur) {
        if(u == s.size())  return cur;
        while(u < s.size() && s[u] != ']') {
            if((s[u] >= 'a' && s[u] <= 'z') || (s[u] >= 'A' && s[u] <= 'Z')) {
                cur += s[u];
                u++;
            } else if(s[u] == '[') {
                u++;
            } else if(isdigit(s[u])) {
                int v = 0;
                while(u < s.size() && isdigit(s[u])) {
                    v = v * 10 + s[u] - '0';
                    u++;
                }
                u = u + 1;
                string temp = dfs(s, u, "");
                for(int i = 0;i < v;i++) cur += temp;
                u++;
            } else if(s[u] == ']') {
                return cur;
            }
        }
        return cur;

    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(c == '(' || c=='[' || c=='{')
                st.push(c);
            else if(c==')')
            {
                if(st.top() == '(')
                st.pop();
                else
                    return false;
            } else if(c == ']')
            {
                if(st.top() == '[')
                    st.pop();
                else
                    return false;
            }else if(c == '}')
            {
                if(st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
    bool isValid_2(string s)
    {
        //括号匹配第二种思路
        stack<char> st;
        for(auto c:s)
        {
            if(c=='(')
                st.push(')');
            else if(c=='{')
                st.push('}');
            else if(c=='[')
                st.push(']');
            else if(!st.empty() && (st.top() == c))
                st.pop();
            else
                return false;
        }
        return st.empty() ? true : false;
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans_pre, ans_mid, ans_back;
        r_traversal(root, ans_pre, ans_mid, ans_back);
    }
    void r_traversal(TreeNode* root, vector<int>& ans_pre, vector<int>& ans_mid, vector<int>& ans_back)
    {
        if(root== nullptr)
            return;
        else
        {
            ans_pre.push_back(root->val);
            r_traversal(root, ans_pre, ans_mid, ans_back);
            ans_mid.push_back(root->val);
            r_traversal(root, ans_pre, ans_mid, ans_back);
            ans_back.push_back(root->val);
            r_traversal(root, ans_pre, ans_mid, ans_back);
        }
    }
//    vector<int> stack_preorderTraversal(TreeNode* root)
//    {
//        vector<int> ans_pre;
//        stack
//        r_traversal(root, ans_pre, ans_mid, ans_back);
//    }

};