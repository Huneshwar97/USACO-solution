// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n;
	cin>>n;
	vector<int> values(n+1);
	vector<long long> psum(n+1);
	psum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>values[i];
		psum[i]=psum[i-1]+values[i];
		psum[i]=psum[i]%7;
	}
	int maxi=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(psum[i]==psum[j]){
				maxi=max(maxi,j-i);
			}
		}
	}	
	cout<<maxi;
	return 0;
}