#include <bits/stdc++.h>
using namespace std;

bool can_reach(int target_value)
{
    queue<int> q;
    int visited[target_value +1] = {false};
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        if (current == target_value)
        {
            return true;
        }
        int plus_three = current + 3;
        int multiply_two = current * 2;
        if (plus_three <= target_value && !visited[plus_three])
        {
            q.push(plus_three);
            visited[plus_three] = true;
        }
        if (multiply_two <= target_value && !visited[multiply_two])
        {
            q.push(multiply_two);
            visited[multiply_two] = true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (can_reach(n))
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