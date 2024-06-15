#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define mod 1000000007
int bin(int a,int n,int p) 
{ 
int res = 1;
 while(n) 
{
 if(n%2)
 {  res = (res*a)%p; n--;}
 else {
  a=(a*a)%p; n/=2;
} 
 }
 return res;
}
 main() {
    int t;
    cin >> t;
    while (t--)
    {
        long long  n;
        long long  a;
        
        cin>>a;
        cin>>n;
        int ans = bin(a,n,mod);
        cout<<ans<<endl;
    }
    





return 0;
}