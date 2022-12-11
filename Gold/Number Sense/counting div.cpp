#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;cin>>x;
        int div=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0 ){
                if(i*i==x){
                    div++;
                }else{
                    div+=2;
                    
                }
            }
        }
        cout<<div<<"\n";
    }
}
