// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;



vector<vector<pair<int, int>>> neighbors(5005);
vector<bool> visited(5005);
long long k;int ans;

void dfs(int node){
    visited[node]=true;
    for(auto x:neighbors[node]){
        if(x.second >=k && !visited[x.first]){
            ans++;
            dfs(x.first);
        }
    }
}

int main(){
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int a,b;
        long long res;
        cin>>a>>b>>res;
        neighbors[a].push_back({b,res});
        neighbors[b].push_back({a,res});
    }
    while(Q--){
        int v;
        cin>>k>>v;
        ans=0;
        dfs(v);
        for(int i=0;i<=N;i++){
            visited[i]=0;
        }
        cout<<ans<<"\n";
    }
}
