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
    }

    int q;
    cin >>q;
    while (q--)
    {
        int a,b;
        cin >> a >> b;
        bool isConnected = false;
        if( a == b){
            isConnected = true;
        }
       else{
        for( int child : adj_list[a]){
            if(child == b){
                isConnected = true;
                break;
            }

        }
       }

        if(isConnected){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}