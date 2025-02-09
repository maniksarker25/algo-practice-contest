#include <bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >>q;
    while (q--)
    {
        int x;
        cin >> x;

        vector<int>nodes;
        for( int child : adj_list[x]){
            
            nodes.push_back(child);
        }
        sort(nodes.begin(),nodes.end(),greater<int>());
        if(nodes.empty()){
            cout << -1 << " ";
        }
        else{
            for(int val : nodes){
                cout << val << " ";
            }
        }
        cout << endl;
        
    }
    
    return 0;
}