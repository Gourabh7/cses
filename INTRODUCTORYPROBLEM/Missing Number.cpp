#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    map<long long int,long long int>mp;
    long long int sum = 0;
    long long  int xorr = 0;
    for(int i = 1;i<n;i++){
        long long int p;
        cin>>p;
        mp[p]++;
        sum += p;
        xorr^=p;
    }
    long long int ans = -1;
    for(int i = 1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            ans = i;
        }
    }
    // cout<<ans<<endl;
    ans = (n*(n+1))/2-sum;
    int delta = 0;
    if(n%4==0){
        delta = n;
    }else if(n%4==1){
        delta = 1;
    }else if(n%4==2){
        delta = n+1;
    }else{
        delta = 0;
    }
    // cout<<ans<<endl;
    ans = (delta^xorr);
    cout<<ans<<endl;
}