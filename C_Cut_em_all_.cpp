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
vi subtr;
ll cnt = 0;
void dfs(ll cur, ll par)
{
    subtr[cur] = 1;
    for (ll nb : adj[cur])
    {
        if (nb == par)
            continue;
        dfs(nb, cur);
        subtr[cur] += subtr[nb];
    }
    if (subtr[cur] % 2 == 0)
        cnt++;
}
void solve()
{
    ll n;
    cin >> n;
    adj.resize(n);
    subtr.assign(n, 0);
    fr(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    if (subtr[0] % 2)
        cout << -1 << '\n';
    else
        cout << cnt - 1 << '\n';
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