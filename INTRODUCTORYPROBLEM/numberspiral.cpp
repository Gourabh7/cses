#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int i,j;
        cin>>i>>j;
        if(i>=j && i%2==0){
            long long int ans = i*i-(j-1);
            cout<<ans<<endl;
        }else if(i>=j && i%2==1){
            long long int ans = (i-1)*(i-1)+1+(j-1);
            cout<<ans<<endl;
        }else if(j%2){
            long long int ans = j*j-(i-1);
            cout<<ans<<endl;
        }else{
            long long int ans = (j-1)*(j-1)+1+(i-1);
            cout<<ans<<endl;
        }
    }
}