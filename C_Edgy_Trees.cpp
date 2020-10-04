#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a))
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll, vll, greater<ll>>
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define mapsl map<string, ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string, ll>
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
const ll MAXN = (ll)(1 * 1e6 + 5);
vvi adj;
vi vis;
ll cnt = 0;
ll powmod(ll x, unsigned ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
void dfs(ll cur)
{
    cnt++;
    vis[cur] = 1;
    for (ll nb : adj[cur])
    {
        if (vis[nb])
            continue;
        dfs(nb);
    }
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    adj.resize(n);
    fr(i, 0, n - 1)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        if (c == 0)
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    ll tot = powmod(n, k, mod);
    ll ans = 0;
    vis.assign(n, 0);
    fr(i, 0, n)
    {
        if (vis[i])
            continue;
        cnt = 0;
        dfs(i);
        ans += powmod(cnt, k, mod);
        ans %= mod;
    }
    cout << (tot - ans + mod) % mod << '\n';
}
int main()
{
    fast();
    ll t = 1;
    //cin >> t;
    //sieve(1e7 + 5);
    fr(i, 0, t)
    {
        solve();
    }
}