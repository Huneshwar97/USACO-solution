#include <bits/stdc++.h>
using namespace std;

const int SZ = 2e5;

vector<int> children[200005];
int subsize[200005];

void dfs(int node){
    subsize[node]=1;
    for(auto x:children[node]){
        dfs(x);
        subsize[node] +=subsize[x];
    }
}

int main() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int parent;cin>>parent;
        
        children[parent].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<subsize[i]-1<<" ";
    }
}
