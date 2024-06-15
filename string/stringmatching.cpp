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
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
//str search kar rahe s me
vector<int> matchingrabin(string str, string s)
{
    int T = s.length();
    int S = str.size();
    int p = 53;
    int MOD = 1e9 + 7;

    int p2 = 31;
    int mod = 1e9 + 5;
    int n = s.size();
    vector<int> p_pow(max(str.size(),s.size()), 1);
    for (int i = 1; i <(str.size(),s.size()) ; i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % MOD;
    }
    vector<int> p_pow2((str.size(),s.size()), 1);

    for (int i = 1; i < (str.size(),s.size()); i++)
    {
        p_pow2[i] = (p_pow2[i - 1] * p2) % mod;
    }

    vector<int> h(n + 1, 0);
    vector<int> h2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % mod;
    }

    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (str[i] - 'a' + 1) * p_pow[i]) % MOD;
    long long h_s2 = 0;
    for (int i = 0; i < S; i++)
        h_s2 = (h_s2 + (str[i] - 'a' + 1) * p_pow2[i]) % mod;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + MOD - h[i]) % MOD;
        long long cur_h2 = (h2[i + S] + mod - h2[i]) % mod;
        if (cur_h == h_s * p_pow[i] % MOD && cur_h2 == h_s2 * p_pow2[i] % mod)
        occurrences.push_back(i);
    }
    return occurrences;
}
vector<int> rabin_karp(string const &s, string const &t)
{
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
main()
{
    fast_io;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = t.size();
    string r = t + '#' + s;
    vi pi = prefix_function(r);
    // out(pi);
    // vi occ = rabin_karp(t, s);
    // cout << occ.size() << nl;
    vi occ = matchingrabin(t,s);
    cout << occ.size() << nl;
    // int cnt=0;
    // for (int i = n; i < r.size(); i++)
    // {
    //     //i-2*n
    //     if (pi[i] == n)
    //     {
    //         cnt++;
    //     }
    // }
    // cout <<cnt<< nl;

    return 0;
}