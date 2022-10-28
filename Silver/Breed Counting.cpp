#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	int N,Q;
	cin>>N>>Q;int x;
	int pa[N];int pb[N];int pc[N];
	pa[0]=0;pb[0]=0;pc[0]=0;
	for(int i=1;i<=N;i++){
		cin>>x;
		if(x==1){
			pa[i]=pa[i-1]+1;
			pb[i]=pb[i-1];
			pc[i]=pc[i-1];
			
		}
		else if(x==2){
			pa[i]=pa[i-1];
			pb[i]=pb[i-1]+1;
			pc[i]=pc[i-1];
		}
		else{
			pa[i]=pa[i-1];
			pb[i]=pb[i-1];
			pc[i]=pc[i-1]+1;
		}
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<pa[r]-pa[l-1]<<" "<<pb[r]-pb[l-1]<<" "<<pc[r]-pc[l-1]<<"\n";
	}
}