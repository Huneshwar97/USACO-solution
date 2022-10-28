#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
	int n;
	cin>>n;
	vector<int> values(n);
	for(int i=0;i<n;i++)
		cin>>values[i];
	ll sum=0;
	map<ll,int> seen;
	seen[0]++;
	ll count =0;//if all the values are 0 and n=10^9 , sum = 0 then count will be all pair n*(n-1)^2 
	for(int i=0;i<n;i++){
		sum +=(values[i]%n);
		sum=(sum+n)%n;
		count+=seen[sum];
		seen[sum]++;
	}
	cout<<count;
 
}