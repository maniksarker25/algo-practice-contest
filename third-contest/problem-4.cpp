#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<pair<long long int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;
            pq.push({h, i});
        }

        int first_idx = pq.top().second;
        pq.pop();
        int second_idx = pq.top().second;

        cout << min(first_idx, second_idx) << ' ' << max(first_idx, second_idx) << endl;
    }

    return 0;
}