// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int mn=3005;

int n,m,ans,k;
vector<int> adj[mn];
bool visited[mn],closed[mn];

void dfs(int node){
	visited[node]=true;
	for(int u:adj[node]){
		if(!closed[u] && !visited[u]){
			dfs(u);
		}

	}
}

void count_comp(){
	ans=0;
	for(int i=1;i<=n;i++){
		if(!closed[i] && !visited[i]){
			dfs(i);
			++ans;
		}
	}
	if(ans > 1) cout<<"NO"<<"\n";
	else cout<<"YES"<<"\n";
}


int main(){
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		count_comp();
		cin>>k;
		closed[k]=true;
		for(int j=1;j<=n;j++) visited[j]=false;
	}

	return 0;
}
