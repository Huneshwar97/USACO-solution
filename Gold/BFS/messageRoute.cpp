
#include <bits/stdc++.h>
using namespace std;

const int nm=100005;

vector<int> adj[nm];
int n,m;
bool vist[nm];
int prnt[nm]={0};
vector<int> dist(nm+1,INT_MAX);

void bfs(){
    vist[1]=true;
    queue<int> q;
    q.push(1);
    
    dist[1]=1; 
    prnt[1]=0;
    
    while(!q.empty()){
        int crnt=q.front();
        q.pop();
        for(auto nbr:adj[crnt]){
            if(!vist[nbr]){
                vist[nbr]=true;
                dist[nbr]=dist[crnt]+1;
                prnt[nbr]=crnt;
                q.push(nbr);
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    while (m--) {
		int a,b; 
		cin >> a >> b;
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}

	bfs();
	if (dist[n] == INT_MAX) 
	    cout << "IMPOSSIBLE";
	else{
	    cout << dist[n] << "\n";
	    vector<int> ans;
	    int path=n;
	    while(path !=0){
	        ans.push_back(path);
	        path=prnt[path];
	    }
	    reverse(begin(ans),end(ans));
	    for(int node:ans){
	        cout<<node<<" ";
	    }
	}
    
    
    
    
    return 0;
}
