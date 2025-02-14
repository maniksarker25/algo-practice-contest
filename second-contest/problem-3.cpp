#include <bits/stdc++.h>
using namespace std;

int grid[105][105];
int level[105][105];
int vis[105][105];
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int par_i = parent.first;
        int par_j = parent.second;
        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(ki, kj);
        cout << level[qi][qj] << endl;
    }

    return 0;
}