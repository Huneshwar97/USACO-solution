#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+10;//10^5

int n,m;
vector<int> adj[MN];
bool vis[MN];
long long uc=0,c=0;

void dfs(int node, bool g){
    vis[node]=true;
    if(g==0){
        uc++;
    }
    else{
        c++;
    }
    for(auto x:adj[node]){
        if(!vis[x]){
            dfs(x,!g);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << c * uc - (n - 1) << "\n";
}