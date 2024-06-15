#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int bin(long long int a,long long int n,long long int p) 
{long long int res = 1; while(n) 
{ 
    if(n%2)
 {  res = (res*a)%p; n--;} 
else {  a=(a*a)%p; n/=2;} 
 }
 return res;}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int b;
        long long int a;

        cin >> a;
        cin >> b;
        long long int c;
        cin >> c;
        long long int n = bin(b, c,mod-1);
        long long int ans = bin(a,n, mod);
        cout << ans << endl;
    }

    return 0;
}