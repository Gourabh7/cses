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

void mul(int A[][2], int B[][2], int n, int m)
{
    int res[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                res[i][j] = res[i][j] % m + (A[i][k] * B[k][j]) % m;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (res[i][j] % m);
        }
    }
}
void power(int ar[][2], int n, int p, int m)
{
    int I[2][2];
    I[0][0] = 1;
    I[1][1] = 1;
    I[0][1] = 0;
    I[1][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    while (p)
    {
        if (p % 2)
        {
            mul(I, ar, n, m);
            p--;
        }
        else
        {
            mul(ar, ar, n, m);
            p /= 2;
        }
    }

    // for (int i = 0; i < p; i++)
    // {
    //     mul(I,ar,n);
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ar[i][j] = I[i][j];
        }
    }
}
// recurence relation
//  1*k matrix where k is values on which current element depends on
// fib [0, 1]
//[ 1,1]
void solve()
{
    int n;
    cin >> n;
    int lis[2][2];
    lis[0][0] = 0;
    lis[0][1] = 1;
    lis[1][0] = 1;
    lis[1][1] = 1;
    int fib[1][2];
    fib[0][0] = 0;
    fib[0][1] = 1;
    power(lis, 2, n, mod);
    mul(fib, lis, 2, mod);
    int ans = fib[0][0] % mod;
    cout << ans << endl;
}
main()
{
    fast_io;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}