#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int group_size[100005];
int dsu_find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node_1, int node_2)
{
    int leader1 = dsu_find(node_1);
    int leader2 = dsu_find(node_2);

    if (group_size[leader1] >= group_size[leader2])
    {
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{

    for (int i = 0; i < 100005; i++)
    {
        group_size[i] = 1;
        parent[i] = -1;
    }

    int n, e;
    cin >> n >> e;
    int cycle_count = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            cycle_count++;
        }

        else
        {
            dsu_union(a, b);
        }
    }

    cout << cycle_count << endl;
    return 0;
}