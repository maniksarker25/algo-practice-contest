#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];

vector<pair<int,int>>d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;



bool valid(int i,int j){
    if(i<0 || i >= n || j < 0 || j>=m || grid[i][j] == '#'){
        return false;
    }
    return true;
}
void dfs(int si,int sj){
    vis[si][sj] = true;
    for(int i =0;i<4;i++){
      int ci = si + d[i].first;
      int cj = sj + d[i].second;
       if(valid(ci,cj) ==true && !vis[ci][cj]){
        dfs(ci,cj);
       }
    }
}
int main()
{

    cin >> n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
           cin >> grid[i][j];
        }
    }
    int si = -1,sj =-1;
    int di =-1,dj=-1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
           if(grid[i][j] == 'A'){
            si = i;
            sj = j;
           }
           if(grid[i][j] == 'B'){
            di = i;
            dj = j;
           }
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(si,sj);

    if(vis[di][dj] == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}   