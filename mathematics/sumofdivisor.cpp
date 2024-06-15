#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int bin(long long int a,long long int n){
    long long int res=1;
while(n>0){
if(n%2==0){
    a = a*a%mod;
}else{
    res = res*a%mod;
}
}
return res;
}
int main() {
long long int n;
cin>>n;
map<int,int>mp;
for(int i=2;i<=sqrt(n);i++) {
    if(n%i==0){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
}
if(mp.size()==0){
    n++;
    cout<<n<<endl;
    return 0;
}
long long int ans =1;
for(auto it:mp){
    long long int a = it.first;
    long long int b = it.second+1;
long long int val = (bin(a,b)-1+mod)%mod;
long long int val1 = (a,mod-2)%mod;
ans = val*val1%mod;
}
cout<<ans<<endl;
return 0;
}