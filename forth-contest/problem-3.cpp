#include <bits/stdc++.h>
using namespace std;

bool can_reach(int target_value, int current_value)
{
    if (current_value > target_value)
    {
        return false;
    }
    if (current_value == target_value)
    {
        return true;
    }
    return can_reach(target_value, current_value + 3) || can_reach(target_value, current_value * 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int ans = can_reach(n, 1);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}