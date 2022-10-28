#include <bits/stdc++.h>
using namespace std;



int main(){
    int n , q;
    cin>>n>>q;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<long long> psum(n+1);
    psum[0]=0;
    for(int i=1;i<=n;i++){
        psum[i]=psum[i-1]+a[i];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<psum[r]-psum[l]<<endl;
    }
    
}