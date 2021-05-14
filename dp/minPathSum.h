//
// Created by yuanh on 2021/5/9.
//

#ifndef LEET_CODE_MINPATHSUM_H
#define LEET_CODE_MINPATHSUM_H

#endif //LEET_CODE_MINPATHSUM_H
#include <vector>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if (grid.size()==0 && grid[0].size()==0)
            return 0;
        if (grid.size()==1)
        {
            int res=0;
            for (int i = 0; i < grid[0].size(); ++i)
            {
                res += grid[0][i];
            }
            return res;
        }
        if (grid[0].size()==1)
        {
            int res=0;
            for (int i = 0; i < grid.size(); ++i)
            {
                res += grid[i][0];
            }
            return res;
        }

        vector<vector<int>>right;
        for (int i = 0; i < grid.size(); ++i)
        {
            vector<int> tmp{grid[i].begin()+1, grid[i].end()};
            right.push_back(tmp);
        }
        int go_right = minPathSum(right);
        vector<vector<int>>down;
        for (int i = 1; i < grid.size(); ++i)
        {
            down.push_back(grid[i]);
        }
        int go_down = minPathSum(down);
        return min(go_down, go_right)+grid[0][0];
    }
    int minPathSum2(vector<vector<int>>& grid)
    {
        int width = grid[0].size(), high = grid.size();
        if (width == 0 && high == 0)
            return 0;
        for (int i = 1; i < width; ++i)
        {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < high; ++i)
        {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < high; ++i)
        {
            for (int j = 1; j < width; ++j)
            {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[high-1][width-1];
    }
};