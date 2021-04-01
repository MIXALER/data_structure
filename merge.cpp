//
// Created by yuanh on 2021/3/19.
//

#include <vector>

using  namespace std;

vector<int> merge(vector<int> num1, vector<int> num2)
{

}

int main()
{
    vector<vector<int>> for_sort(5, vector<int>(10, 0));
    vector<vector<int>> ans;
    vector<int> temp;

    int k;
    int temp_k;

    while(k >=1)
    {
            for(int i = 0; i<k-1; i+=2)
            {
                temp = merge(for_sort[i], for_sort[i+1]);
                ans.push_back(temp);
            }
            k = ans.size();

            ans = ans[-k:0];
            k = k/2;
    }
    vector<int > =

}