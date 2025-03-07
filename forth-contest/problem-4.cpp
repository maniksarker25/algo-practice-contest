#include <bits/stdc++.h>
using namespace std;

int values[1005], weights[1005];
int dp[1005][1005];
int adventure(int i, int max_weight)
{
    if (i < 0 || max_weight <= 0)
    {
        return 0;
    }
    if (dp[i][max_weight] != -1)
    {
        return dp[i][max_weight];
    }
    if (weights[i] <= max_weight)
    {
        int opt1 = adventure(i - 1, max_weight - weights[i]) + values[i];
        int opt2 = adventure(i - 1, max_weight);
        dp[i][max_weight] = max(opt1, opt2);
        return dp[i][max_weight];
    }
    else
    {
        dp[i][max_weight] = adventure(i - 1, max_weight);
        return dp[i][max_weight];
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n, w;
        cin >> n >> w;
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        int ans = adventure(n - 1, w);
        cout << ans << endl;
    }

    return 0;
}