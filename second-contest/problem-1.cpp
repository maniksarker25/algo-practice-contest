#include <bits/stdc++.h>
using namespace std;

char grid[10005][1005];
vector<pair<int,int>>d = {{-1,0},{1,0},{0,-1},{0,1}};
bool vis[1005][1005];
int n,m;

bool valid(int i , int j){
    if(i < 0 || i >=n || j < 0 || j >=m){
        return false;
    }
    return true;
}

void dfs(int si,int sj){
    vis[si][sj] = true;
    for(int i = 0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci,cj);
        }
    }


}

int main()
{
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    int si,sj;
    cin >> si >> sj;
    int di,dj;
    cin >> di >> dj;
    memset(vis,false,sizeof(vis));
    dfs(si,sj);
    if(vis[di][dj]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}