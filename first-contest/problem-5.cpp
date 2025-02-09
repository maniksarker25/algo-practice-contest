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

void dfs(int si,int sj,int &roomCount){
    vis[si][sj] = true;
    roomCount++;
    for(int i =0;i<4;i++){
      int ci = si + d[i].first;
      int cj = sj + d[i].second;
       if(valid(ci,cj) ==true && !vis[ci][cj]){
        dfs(ci,cj,roomCount);
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
    memset(vis,false,sizeof(vis));
    vector<int>apartmentRooms;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(vis[i][j] == false && grid[i][j] == '.'){
                int roomCount = 0;
                dfs(i,j,roomCount);
                apartmentRooms.push_back(roomCount);
            }
        }
    }
    sort(apartmentRooms.begin(),apartmentRooms.end());
   if(apartmentRooms.empty()){
    cout << 0 << endl;
   }
   else {
    for(int room : apartmentRooms){
        cout << room << " ";
    }
   }
    return 0;
}   