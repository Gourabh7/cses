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
void build(int ind,vi &seg,vi &v,int low,int high){
    if(low==high){
        seg[ind] = v[low];
        return;
    }
    int mid = low+(high-low)/2;
    build(2*ind+1,seg,v,low,mid);
    build(2*ind+2,seg,v,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);

}
void update(int ind,vi &seg,vi &v,int low,int high,int l){
   if(low==high ){
    seg[ind] = v[l];
    return;
   }
    int mid = low+(high-low)/2;
    if(l<=mid){
        update(2*ind+1,seg,v,low,mid,l);
    }else{
        update(2*ind+2,seg,v,mid+1,high,l);
    }
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,vi &seg,int low,int high,int start,int end){
      if(low>=start && high<=end){
        return seg[ind];

    }
    if(low>end || high<start){
        return 0;
    }
    if(low==high){
        return seg[ind];
    }
  
    int mid = low+(high-low)/2;
    int left = query(2*ind+1,seg,low,mid,start,end);
    int right = query(2*ind+2,seg,mid+1,high,start,end);
    return max(left,right);

}

main()  {
fast_io;
int n,m;
cin >> n>>m;
vi v;
read(v,n);
vi seg(4*n,0);
build(0,seg,v,0,n-1);
// int l = query(0,seg,0,n-1,0,n-1);
// cout<<l<<" ";
while(m--){
    int a;
    cin>>a;
    int start = 0;
    int end = n-1;
    int ans =-1;
    if(query(0,seg,0,n-1,0,n-1)<a){
        cout<<0<<" ";
        // out(v);
        continue;
    }
    while(start<=end){
        int mid = start+(end-start)/2;
        if(query(0,seg,0,n-1,start,mid)>=a){
            ans = mid;
            end = mid-1;
        }else if(query(0,seg,0,n-1,mid+1,end)>=a){
            ans=mid+1;
            start =mid+1;
        }else{
            break;
        }
    }
        
        v[ans]-=a;
        update(0,seg,v,0,n-1,ans);
        cout<<(ans+1)<<" ";
        // out(v);
    
}
return 0;
}