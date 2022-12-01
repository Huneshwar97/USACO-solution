// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() 
{
 freopen("cowqueue.in","r",stdin);
 freopen("cowqueue.out","w",stdout);

 int n;
 cin>>n;
 vector<pair<int,int>> v;
 for(int i=0; i<n; i++){
 	int x, y;
 	cin>>x>>y;
 	v.push_back({x,y});
 }
 sort(v.begin(),v.end());
 int nextAvailableTime=0;
 for(pair<int,int>p: v){
	if(nextAvailableTime < p.first)
		nextAvailableTime=p.first + p.second;
	else
		nextAvailableTime+=p.second;
   }
   cout<<nextAvailableTime;
 }