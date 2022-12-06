// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

struct walkie {
	int x,y,p;
};

vector<int> adj[200];
bool visited[200];
int cowReached;

void DFS (int node){
	if(visited[node]){
		return;
	}
	cowReached++;
	visited[node] = true;
	for(int connectedCow : adj[node]){
		DFS(connectedCow);
	}
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n;
	cin>>n;
	vector<walkie> cow(n);
	for(int i=0;i<n;i++){
		cin>>cow[i].x>>cow[i].y>>cow[i].p;
	}
	//calculate distance between everypair
	for(int i=0;i<n;i++){
		for(int j = 0; j < n; j++){
			int distx=cow[i].x-cow[j].x;
			int disty=cow[i].y-cow[j].y;
			long long dist = ( distx * distx ) + ( disty * disty );
			if(dist <= (cow[i].p*cow[i].p)){
				adj[i].push_back(j);
			}
		}
	}
	int maxCowsReached = 1;
	for(int i=0;i<n;i++){//call dfs through every node 
		cowReached = 0;
		fill(visited,visited+n,false);//to mark all node to visited false//we can do it at last also
		DFS(i);
		maxCowsReached = max(maxCowsReached,cowReached);
	}
	cout<< maxCowsReached << endl;

}
