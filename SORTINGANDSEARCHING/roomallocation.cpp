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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    map<int, set<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, {a, i}});
        
    }
    sort(all(v));
    for(int i = 0; i < n; i++){
        int a = v[i].second.first;
        mp[a].insert(i);
    }
    // for(auto it:mp){
    //     cout<<it.first<<" -> ";
    //     for(auto itt:mp[it.first]){
    //         cout<<itt<<" ";
    //     }
    //     cout<<nl;
    // }
    // cout<<nl;
    vi vis(n, 0);
    int cnt = 1;
    int j = 0;
    vi ans(n, 0);
    bool flag;
    while (j < v.size())
    {
        int save = j;
        flag = false;
        while (true)
        {
            // flag = true;
            if(ans[v[save].second.second]==0){
            flag=true;
            ans[v[save].second.second] = cnt;
                        vis[save]=1;
            auto it = mp.upper_bound(v[save].first);
        
            int r  = *(mp[v[save].second.first].begin());
            mp[v[save].second.first].erase(r);
            if(mp[v[save].second.first].empty()){
                mp.erase(v[save].second.first);
            }
    //             for(auto ity:mp){
    //     cout<<ity.first<<" -> ";
    //     for(auto itt:mp[ity.first]){
    //         cout<<itt<<" ";
    //     }
    //     cout<<nl;
    // }
    // cout<<nl;
            if(it==mp.end()){
                break;
            }
            int vl = (*it).first;
            save = *(mp[vl].begin());
            // if(vl==10)
            // cout<<save<<nl;
            }else{
                break;
            }
        

           
            
        }
        if (flag)
            cnt++;
        j++;
    }
    cnt--;
    cout<<cnt<<nl;
    out(ans);
    return 0;
}