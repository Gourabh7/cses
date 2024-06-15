#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int prev;
    cin>>prev;
    long long int ans = 0;
    long long int maxi = prev;
    for(int i=1; i<n; i++){
        long long int p;
        cin>>p;
        if(p<=maxi){
            ans+= abs(maxi-p);
        }
        else{
            maxi = p;
        }
    }
    cout<<ans<<endl;

}