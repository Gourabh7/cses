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
void build(int ind, vi &seg, vi &x, int low, int high)
{
    if (low == high)
    {
        seg[ind] = x[low];
        // cout << low << " " << seg[ind] << nl;
        return;
    }
    int mid = low + (high - low) / 2;

    build(2 * ind + 1, seg, x, low, mid);
    build(2 * ind + 2, seg, x, mid + 1, high);

    // seg[ind] =
}
void update(int ind, vi &seg, int low, int high, int l, int r, int u)
{
    if (low >= l && high <= r)
    {
        seg[ind] += u;
        return;
    }
    if (high < l || low > r)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    update(2*ind+1, seg, low, mid, l, r, u);
    update(2*ind+2, seg, mid + 1, high, l, r, u);
}
int query(int ind, vi &seg, int low, int high, int k)
{
    if (low == high)
    {
        return seg[ind];
    }
    if (seg[ind] != 0)
    {
        seg[2 * ind + 1] += seg[ind];
        seg[2 * ind + 2] += seg[ind];
        seg[ind] = 0;
    }
    int mid = low + (high - low) / 2;
    if (k <= mid)
    {
        return query(2 * ind + 1, seg, low, mid, k);
    }
    return query(2 * ind + 2, seg, mid + 1, high, k);
}
main()
{
    fast_io;
    int n, q;
    cin >> n >> q;
    vi x;
    vi seg(4 * n, 0);
    read(x, n);
    build(0, seg, x, 0, n - 1);
    // out(seg);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            update(0, seg, 0, n - 1, a, b, u);
            // out(seg);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            int val = query(0, seg, 0, n - 1, k);
            cout << val << endl;
        }
    }

    return 0;
}