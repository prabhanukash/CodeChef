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
const ll MAXN = (ll)(1 * 1e5 + 5);
ll n, m;
ll x[MAXN], y[MAXN], vx[MAXN], vy[MAXN], valx[MAXN], valy[MAXN];
void solve()
{
    cin >> n >> m;
    fr(i, 1, n + 1) cin >> x[i] >> vx[i];
    fr(i, 1, m + 1) cin >> y[i] >> vy[i];
    fr(i, 1, n + 1) valx[i] = x[i] * vx[i];
    fr(i, 1, m + 1) valy[i] = y[i] * vy[i];
    map<ll, ll> mx, my;
    fr(i, 1, n + 1) mx[valx[i]]++;
    fr(i, 1, m + 1) my[valy[i]]++;
    vi v;
    fr(i, 1, n + 1) v.pb(valx[i]);
    fr(i, 1, m + 1) v.pb(valy[i]);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    ll ans = 0;
    fr(i, 0, v.S)
    {
        ans += min(mx[v[i]], my[v[i]]);
    }
    cout << ans << '\n';
}
int main()
{
    fast();
    ll t = 1;
    //cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}