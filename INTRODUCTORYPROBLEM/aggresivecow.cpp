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
bool istrue(int mid,vi &lis,int c){
        c--;
        int prev = lis[0];
        for(int i = 1;i<lis.size();i++){
            if((lis[i]-prev)>=mid){
                c--;
                prev = lis[i];
            }
        }
        
        // return false;
        return (c<=0);
}
void solve()
{
    int n,c;
    cin>>n>>c;
    vi lis;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        lis.push_back(p);
    }
    sort(all(lis));
    // out(lis);
    int start = 0;;
    int end  = 1e9;
    int ans = 0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(istrue(mid,lis,c)){
            // cout<<mid<<" ";
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<<ans<<endl;
}
main()  {
fast_io;
int t;
t=1;
cin>>t;
while(t--) {
solve();
}
return 0;
}