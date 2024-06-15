#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
bool compare(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
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
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
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
#define read(v, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int p;                  \
        cin >> p;               \
        v.push_back(p);         \
    }
main()
{
    fast_io;
    int n, m;

    cin >> n >> m;
    ;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    vector<int>dist(n+1,1e18);
    vector<int>disc(n+1,1e18);
    // vector<pair<int, int>> dist(n + 1, {1e18, 1e18});
    while (!pq.empty())
    {
        int node = pq.top().second.first;
        int wt = pq.top().first;
        int coupantaken = pq.top().second.second;
        pq.pop();
        if(coupantaken){
        if(disc[node]<wt){
            continue;
        }
        }else{
            if(dist[node]<wt){
                continue;
            }
        }
        
        for (auto it : adj[node])
        {
            if (coupantaken)
            {
                if (disc[it.first] > (wt + it.second))
                {
                    disc[it.first] = wt + it.second;
                    pq.push({disc[it.first], {it.first, coupantaken}});
                }
            }
            else
            {
                if (dist[it.first] > (wt + it.second))
                {
                    dist[it.first] = (wt + it.second);
                    pq.push({dist[it.first], {it.first, coupantaken}});
                   
                }
                 if (disc[it.first]> (wt + it.second / 2))
                    {
                        disc[it.first] = wt + it.second / 2;
                        pq.push({disc[it.first], {it.first, 1}});
                    }
            }
        }
        
    }
    int ans = min(disc[n], dist[n]);
        cout << ans << nl;
    return 0;
}