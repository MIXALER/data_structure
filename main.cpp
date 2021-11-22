#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, W;
    cin >> n;
    cin >> W;
    vector<int> wt;
    vector<int> val;
    for (int i = 0; i < n; ++i)
    {
        int tmp_n;
        int tmp_w;
        cin >> tmp_w;
        cin >> tmp_n;
        wt.push_back(tmp_w);
        val.push_back(tmp_n);
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (W - wt[i - 1] < 0)
            {
                dp[i][w] = dp[i - 1][w];
            } else
            {
                dp[i][w] = max(
                        max(dp[i - 1][w - wt[i - 1]] + val[i - 1], dp[i - 1][w - 2 * wt[i - 1]] + 2 * val[i - 1]),
                        dp[i - 1][w]);
            }
        }
    }
    cout << dp[n][W];
}
