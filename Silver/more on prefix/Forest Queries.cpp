#include <bits/stdc++.h>
using namespace std;

int MAX_SIDE = 1000;
int forest[1001][1001];
int tree_pref[1001][1001];

int main(){
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        char a;
        cin>>a;
        forest[i+1][j+1] += a=='*';
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            tree_pref[i][j]=tree_pref[i-1][j]+tree_pref[i][j-1]+forest[i][j]-tree_pref[i-1][j-1];
        }
    }

    while(Q--){
        int a,A,b,B;
        cin>>a>>b>>A>>B;
        cout<<tree_pref[A][B]-tree_pref[a-1][B]-tree_pref[A][b-1]+tree_pref[a-1][b-1]<<endl;
    }
}