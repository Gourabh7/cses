#include<bits/stdc++.h>
using namespace std;
#define int  long long int 
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) a.begin(), a.end()
#define mp make_pair
#define mod 1000000007
#define nl '\n'
int gcd(int a, int b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}
int lcm(int a, int b)  
{  
    return (a / gcd(a, b)) * b; 
}  
bool compare(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    return p1.first>p2.first;
    return p1.second<p2.second;
}
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){ if(a<b)return a;return b;}
int computeXOR(int n)
{if (n % 4 == 0)  return n; if (n % 4 == 1) return 1; if (n % 4 == 2)   return n + 1; return 0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
#define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define out(v) for(int i = 0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<nl;
#define pre(pref,v) for(int i = 0;i<v.size();i++) { pref.push_back(v[i]); if(i>=1) pref[i]+=pref[i-1];}
#define suf(suff,v) for(int i = 0;i<v.size();i++) {suff.push_back(v[i]); } for(int i=v.size()-2;i>=0;i--){ suff[i]+=suff[i+1];}
#define read(v,n) for(int i = 0;i<n;i++){ int p; cin>>p; v.push_back(p);}
main()  {
fast_io;
int n,q;
cin>>n>>q;
vector<vector<int>>v(n,vector<int>(n,0));
// vector<vector<int>>st(n,vector<int>(n,0));
for(int i = 0;i<n;i++)
{
    for(int j = 0;j<n;j++)
    {
        char ch;
        cin>>ch;
        if(ch=='*'){
            v[i][j] = 1;
            // st[i][j]=1;
        }
    }
}
for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        if(i==0){
            if(j>=1){
                 v[i][j]+=v[i][j-1];
            }
           
        }
        if(j==0)
        {
            if(i>=1){
                v[i][j]+=v[i-1][j];
            }
        }
        if(i>=1 && j>=1){
            v[i][j]+=(v[i-1][j]+v[i][j-1]-v[i-1][j-1]);

    }

}
}
while(q--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;
    y1--;
    x2--;
    y2--;
    int ans = v[x2][y2];
    if(y1>=1)
    ans-=v[x2][y1-1];
    if(x1>=1)
    ans-=v[x1-1][y2];

    if(x1>=1 && y1>=1)
    ans+=(v[x1-1][y1-1]);
    cout<<ans<<nl;
}

return 0;
}