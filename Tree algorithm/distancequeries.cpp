#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int bin(int a, int n, int p)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % p;
            n--;
        }
        else
        {
            a = (a * a) % p;
            n /= 2;
        }
    }
    return res;
}
void primefactorizationoptimized(int n, vector<pair<int, int>> &v)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            v.push_back({i, cnt});
        }
    }
    if (n > 1)
    {
        v.push_back({n, 1});
    }
}
bool is_prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void sieve(bool ar[90000001], vector<int> pn)
{
    int maxN = 90000000;
    ar[0] = ar[1] = true;
    for (int i = 2; i * i < maxN; i++)
    {
        if (!ar[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                ar[j] = true;
            }
        }
    }
    for (int i = 2; i <= maxN; i++)
    {
        if (!ar[i])
        {
            pn.push_back(i);
        }
    }
}
#define nl '\n'
int my_sqrt(int a)
{
    int l = 0, r = 5000000001;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (1ll * mid * mid <= a)
            l = mid;
        else
            r = mid;
    }
    return l;
}

#define out(v)                         \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << nl;
#define pre(pref, v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        pref.push_back(v[i]);          \
        if (i >= 1)                    \
            pref[i] += pref[i - 1];    \
    }
#define suf(suff, v)                        \
    for (int i = 0; i < v.size(); i++)      \
    {                                       \
        suff.push_back(v[i]);               \
    }                                       \
    for (int i = v.size() - 2; i >= 0; i--) \
    {                                       \
        suff[i] += suff[i + 1];             \
    }
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int addm(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
int mulm(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int dmod(int a, int b, int m)
{
    int res = ((a % m) * (bin(b, m - 2, m)) % m) % m;
    return res;
}
int smod(int a, int b, int m)
{
    int res = (m + a % m - b % m) % m;
    return res;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void dfs(int node, vector<vector<int>> &adj, vi &vis, int h, vi &level,vi &par)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            level[it] = h;
            par[it]=node;
            dfs(it, adj, vis, h + 1, level,par);
        }
    }
}
int C(int n, int k, int F[1000001])
{
    if (k > n)
    {
        return 0;
    }
    F[0] = 1;
    for (int i = 1; i <= n; i++)
        F[i] = (F[i - 1] * i) % mod;
    int res = F[n] % mod;
    res = (res * bin(F[k], mod - 2, mod)) % mod;
    res = (res * bin(F[n - k], mod - 2, mod)) % mod;
    return res % mod;
}
#define read(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int p;                  \
        cin >> p;               \
        v.push_back(p);         \
    }
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
main()
{
    fast_io;

    int n, q;

    cin >> n >> q;
    vi par(n + 1, -1);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int u,v;   
        cin>>u>>v;
             adj[u].push_back(v);
        adj[v].push_back(u);
     
    }
    vi level(n + 1, 0);
    vi vis(n + 1, 0);
    dfs(1, adj, vis, 1, level,par);
    // out(level);
    vector<vector<int>> grid(31, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
    {
        grid[0][i] = par[i];
    }
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p = grid[i - 1][j];
            if (p == -1)
            {
                grid[i][j] = -1;
                continue;
            }
            grid[i][j] = grid[i - 1][p];
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int a = u;
        int b = v;

        if (level[u] > level[v])
        {
            v = u;
            u = b;
        }
        a=u;
        b=v;
        int k = level[v] - level[u];
        // cout<<k<<" ";
        for (int i = 30; i >= 0; i--)
        {
            int l = pow(2, i);
            if (((k & l)))
            {
                // cout << l << " ";
                if (v != -1)
                    v = grid[i][v];
            }
        }
        // cout<<u<<" ";
        for (int i = 30; i >= 0; i--)
        {
            if (u != -1 && v != -1 && grid[i][u] != grid[i][v])
            {
                u = grid[i][u];
                v = grid[i][v];
            }
        }
        if(u==b   || v==a){
            cout<<abs(max(level[a],level[b])-min(level[a],level[b]))<<nl;
        //    cout<<" "<<"3"<<nl;
           continue;
        }
       
        int ans = 1;
        if (u != -1)
            ans = grid[0][u];
            if(ans==-1){
                ans = level[a]+level[b]-2*level[1];
                cout<<ans<<nl;
            }else{
                ans = level[a]+level[b]-2*level[ans];
                cout<<ans<<nl;
            }
       
    }

    return 0;
}