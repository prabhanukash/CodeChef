#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a));
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
ll logx(ll base, ll num)
{
    int cnt = 0;
    while (num != 1)
    {
        num /= base;
        ++cnt;
    }
    return cnt;
}
vi vin(ll n)
{
    vi a(n);
    fr(i, 0, n) cin >> a[i];
    return a;
}
void out(vi a)
{
    for (int i = 0; i < (ll)a.S; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void in(ll *a, ll n)
{
    for (ll i = 0; i < n; i++)
        cin >> a[i];
}
void out(ll *a, ll n)
{
    fr(i, 1, n + 1) { cout << a[i] << " "; }
    cout << '\n';
}
void out1(vi v)
{
    fr(i, 0, (ll)v.S) { cout << v[i] << " "; }
    cout << endl;
}
//----------------------------------------START-------------------------------------------
const ll maxN = (ll)(1 * 1e5 + 5);
class union_find
{

public:
    int *pr;
    int *sz;

    union_find(int n)
    {
        pr = new int[n + 1];
        sz = new int[n + 1];

        for (int i = 1; i <= n; ++i)
            pr[i] = i, sz[i] = 1;
    }

    int root(int i)
    {
        if (pr[i] == i)
            return i;

        return pr[i] = root(pr[pr[i]]);
    }

    int find(int i, int j)
    {
        return (root(i) == root(j));
    }

    int un(int i, int j)
    {
        int u = root(i);
        int v = root(j);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        pr[v] = u;
        sz[u] += sz[v];

        return 1;
    }
}; //default indexing is 1-based
void solve()
{
    int n;
    cin >> n;

    vi nodes[26];

    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;

        for (char ch : s)
        {
            int id = ch - 'a';
            nodes[id].pb(i);
        }
    }

    int comp = n;
    union_find dsu(n);

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j + 1 < nodes[i].size(); ++j)
        {
            int u = nodes[i][j];
            int v = nodes[i][j + 1];

            comp -= dsu.un(u, v);
        }
    }

    /*int ans=0;
	for(int i=1;i<=n;++i)
		if(dsu.root(i)==i)
			ans++;*/

    cout << comp << '\n';
}
int main()

{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
#endif
    ll t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
