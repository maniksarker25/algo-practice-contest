#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long int w;
    Edge(int a, int b, long long int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int n, e;
vector<Edge> edge_list;
long long int dis[1005];
bool cycle;

void bellman_ford(int src)
{
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b;
            long long int  w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
            if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    for (auto ed : edge_list)
    {
            int a, b;
            long long int  w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
        if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
        {
            cout << "Negative Cycle Detected" << endl;
            cycle = true;
            return;
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }

    int src;
    cin >> src;

    cycle = false;
    bellman_ford(src);

    if (!cycle)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;

            if (dis[d] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}
