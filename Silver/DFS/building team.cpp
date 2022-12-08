#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+10;//10^5

int n,m;
vector<int> adj[MN];
bool vis[MN];
bool nosol;//for no solution
bool group[MN];
bool bad;

void dfs(int node,bool g=0){
    vis[node]=true;
    group[node]=g;
    for(auto x:adj[node]){
        if(vis[x]){
            if(group[x]==g)//IF both same colour
				bad=1;
        }
        else{
            dfs(x,!g);
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(bad){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<group[i]+1<<" ";
        }
        cout<<"\n";
    }
}
