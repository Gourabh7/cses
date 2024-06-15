#include<bits/stdc++.h>
using namespace std;
#define int  long long int 
#define mod 1000000007
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
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 101
int ARR[3];
int II[3][3],T[3][3];
void mul(int A[3][3],int B[3][3], int dim) {int res[dim+1][dim+1];for(int i =1;i<=dim;i++) {for(int j =1;j<=dim;j++) {res[i][j] = 0;for(int k =1;k<=dim;k++) {int x = (A[i][k] * B[k][j])%1000000007;res[i][j] = (res[i][j] + x)%1000000007;   } }}for(int i = 1;i<=dim;i++) {for(int j = 1;j<=dim;j++) {A[i][j] = res[i][j];}}}
    
int getfib(int n) {if(n<=2) {return ARR[n];}II[1][1] = II[2][2] = 1;II[1][2] = II[2][1] = 0;T[1][1] = 0;T[1][2] = T[2][2] = T[2][1] = 1;n = n-1;while(n) { if(n%2)mul(II,T,2),n--;else mul(T,T,2),n/=2;}int x = (ARR[1]*II[1][1]+ARR[2]*II[2][1])%1000000007;return x;} 
int log(int x)
{
    int now=64;
    return now - __builtin_clzll(x) - 1;
}
bool compare(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    return p1.first>p2.first;
    return p1.second<p2.second;
}
 int setBitNumber(int n)
{
  //this will be the answer going to return
  //This will work for 64-bit if using with long long
  //while in-built functions overflow
    int ans = 1;
    while (n) {
        ans *= 2;
        n /= 2;
    }
      ans/=2;
    return ans;
}
bool issubsequence(string& s1, string& s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}
//MEX of an ARRAY inc 0 ->
int mex(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n=arr.size();
    int mex = 0;
    for (int idx = 0; idx < n; idx++)
    {
        if (arr[idx] == mex)
        {
            mex += 1ll;
        }
    }
    return mex;
}
 //Function to find the previous greater element with a variation that we even take 
    // equal ele to be greater
    vector<int> prevLargerElement(vector<int>& nums,int n){
        // Your code here
        vector<int> ans;
        stack<int> s;
        int pg;
        s.push(0);
        ans.push_back(-1);
        for(int i=1;i<n;i++){
            while(s.empty()==false && nums[s.top()]<nums[i]){
                s.pop();
            }
            pg=(s.empty())?-1:s.top();
            ans.push_back(pg);
            s.push(i);
        }
        return ans;
    }
int get_first_bit(long long n){
    return 63 - __builtin_clzll(n);
}

int get_bit_count(long long n){
    return __builtin_popcountll(n);
}
  vector<int> nextLargerElement(vector<int>& nums,int n){
        // Your code here
        vector<int> ans;
        stack<int> s;
        int pg;
        s.push(n-1);
        ans.push_back(n);
        for(int i=n-2;i>=0;i--){
            while(s.empty()==false && nums[s.top()]<=nums[i]){
                s.pop();
            }
            pg=(s.empty())?n:s.top();
            ans.push_back(pg);
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

int AR[N][N], I[N][N];
void mul(int A[][N],int B[][N],int dim) { int res[dim+1][dim+1]; for(int i = 1;i<=dim;i++) {  for(int j = 1;j<=dim;j++){res[i][j] = 0;for(int k = 1;k<=dim;k++) {res[i][j] += A[i][k]*B[k][j];}  }   } for(int i = 1;i<=dim;i++) {for(int j = 1;j<=dim;j++) {A[i][j] = res[i][j];}  }}

void power(int A[][N],int dim,int n) {for(int i = 1;i<=dim;i++) {for(int j = 1;j<=dim;j++){if(i==j) {  I[i][j] = 1; } else {I[i][j] = 0;} }}while(n) { if(n%2){mul(I,A,dim);n--; } else {mul(A,A,dim);n/=2;}}for(int i = 1;i<=dim;i++) {for(int j = 1;j<=dim;j++){A[i][j] = I[i][j]; }}}

int bin(int a,int n,int p) { int res = 1; while(n) { if(n%2) {  res = (res*a)%p; n--;} else {  a=(a*a)%p; n/=2;}  } return res;}

void primefactorizationoptimized(int n,vector<pair<int,int>>&v){  for(int i=2; i*i<=n; i++){ if(n%i==0){ int cnt=0;   while (n%i==0) {cnt++;n/=i;} v.push_back({i,cnt});}}if(n>1) {v.push_back({n,1});}}

bool is_prime(int n) { if(n==1) { return false;}for(int i = 2;i*i<=n;i++) {if(n%i==0) { return false;}}  return true;}



void sieve(bool ar[90000001],vector<int>pn) {int maxN = 90000000;ar[0] = ar[1] = true;for(int i = 2;i*i < maxN;i++) {if(!ar[i]) {for(int j = i*i;j<=maxN;j+=i) {ar[j] = true;}}}for(int i = 2;i<= maxN;i++) {if(!ar[i]) {pn.push_back(i);}} }
#define nl '\n'
int fac[1000001];
void pfac() {int maxN = 1000000;for(int i =1;i<=maxN;i++) {fac[i] = -1;}for(int i = 2;i<=maxN;i++) {if(fac[i] == -1) {     for(int j = i;j<=maxN;j+=i) {if(fac[j] == -1) {fac[j] = i;}}}}}

int my_sqrt(int a)
{
    int l=0,r=5000000001;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(1ll*mid*mid<=a)l=mid;
        else r=mid;
    }
    return l;
}

#define out(v) for(int i = 0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<nl;
#define pre(pref,v) for(int i = 0;i<v.size();i++) { pref.push_back(v[i]); if(i>=1) pref[i]+=pref[i-1];}
#define suf(suff,v) for(int i = 0;i<v.size();i++) {suff.push_back(v[i]); } for(int i=v.size()-2;i>=0;i--){ suff[i]+=suff[i+1];} 
int max(int a,int b){if(a>b)return a;return b;}
int addm(int a,int b) {return ((a%mod)+(b%mod))%mod;}
int mulm(int a,int b) {return ((a%mod)*(b%mod))%mod;}
int dmod(int a,int b,int m) {int res = ((a%m)*(bin(b,m-2,m))%m)%m;return res;}
int smod(int a,int b,int m) {int res = (m+a%m-b%m)%m;return res;}
int min(int a,int b){ if(a<b)return a;return b;}
int gcd(int a, int b) { return b?gcd(b,a%b):a;}  
int lcm(int a, int b) { return a/gcd(a,b)*b;} 

int C(int n, int k,int F[1000001]) {if(k>n) {return 0;}  F[0] = 1;
for (int i = 1; i <= n; i++)
F[i] = (F[i - 1] * i) % mod;int res = F[n]%mod; res = (res*bin(F[k],mod-2,mod))%mod;res = (res*bin(F[n-k],mod-2,mod))%mod; return res%mod;}


class DisjointSet {
vector<int>rank,parent,size;
public:
DisjointSet(int n) {
rank.resize(n+1,0);
parent.resize(n+1);
size.resize(n+1);
for(int i = 0;i<=n;i++) {
parent[i]=i;
}
for(int i = 0;i<=n;i++) {
size[i]=1;
}
}
int findUPar(int node) {
if(node == parent[node])
return node;
return parent[node] =  findUPar(parent[node]);
}
void unionByRank(int u,int v) {
int ulp_u = findUPar(u);
int ulp_v= findUPar(v);
if(ulp_u == ulp_v) return;
if(rank[ulp_u]<rank[ulp_v]) {
parent[ulp_u] = ulp_v;
}else if(rank[ulp_v]<rank[ulp_u] ){
parent[ulp_v] = ulp_u;
}else {
parent[ulp_v] = ulp_u;
rank[ulp_u]++;
}}
void unionBySize(int u,int v) {
int ulp_u = findUPar(u);
int ulp_v= findUPar(v);
if(ulp_u == ulp_v) return;
if(size[ulp_u]<size[ulp_v]){
parent[ulp_u] = ulp_v;
size[ulp_v]+=size[ulp_u];

}else {
parent[ulp_v] = ulp_u;
size[ulp_u]+=size[ulp_v];
}
}
};

void init(int maxN,int phi[1000001]) { for(int i = 1; i <= maxN; i++) phi[i] = i;   for(int i = 2;i<= maxN;i++) { if(phi[i]==i) {for(int j = i;j<=maxN;j+=i) {phi[j]/=i;phi[j]*=(i-1);} }}}

#define read(v,n) for(int i = 0;i<n;i++){ int p; cin>>p; v.push_back(p);}
int computeXOR(int n)
{if (n % 4 == 0)  return n; if (n % 4 == 1) return 1; if (n % 4 == 2)   return n + 1; return 0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
 main()  {
fast_io;
int n,q;
cin>>n>>q;
vi v;
v.push_back(0);
read(v,n);

for(int i =1;i<=n;i++) {
    v[i]^=v[i-1];
}


while(q--){
int a,b;
cin>>a>>b;
int ans = v[b]^v[a-1];
cout<<ans<<nl;
}
return 0;
}
