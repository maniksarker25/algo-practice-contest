#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int vis[1005][1005];
int n , m;
bool valid(int i , int j){
    if(i < 0 || i >=n || j < 0 || j >=m){
        return false;
    }
    return true;
}


int dfs(int si ,int sj){
    if (!valid(si, sj) || grid[si][sj] == '-' || vis[si][sj]) {
        return 0;
    }
    int sum = 1;
    vis[si][sj] = true;
    sum+= dfs(si,sj+1);
    sum+= dfs(si,sj-1);
    sum+= dfs(si+1,sj);
    sum+= dfs(si-1,sj);
    return sum;
}
int main()
{

    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int minimumComponent = INT_MAX;
    bool isComAvailable = false;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j] == '.' && !vis[i][j]){
               isComAvailable = true;
               int totalComponent = dfs(i,j);
               minimumComponent = min(minimumComponent,totalComponent);
            }
        }
    }
    if(isComAvailable){
        cout << minimumComponent << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}