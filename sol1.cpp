#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1000000009)
#define mset(a,k) memset(a,k,sizeof(a));
#define fr(i, x, y) for ( ll i = x; i < y;i++)
#define dr(i, x, y) for ( ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll,vll ,greater<ll>>
#define mapcl map<char,ll>
#define mapll map<ll,ll>
#define mapsl map<string,ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string,ll>
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
#define vvi vector<vi>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
ll gcd(ll x, ll y )						{if (y == 0) return x; return gcd(y, x % y);}
ll lcm(ll a, ll b)						{return (a * b) / gcd(a, b);}
ll logx(ll base, ll num)				{int cnt = 0; while (num != 1) {num /= base; ++cnt;} return cnt;}
vi vin(ll n)							{vi a(n); fr(i, 0, n) cin >> a[i]; return a;}
void in(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void out(ll *a, ll n)					{fr(i, 0, n) {cout << a[i] << " ";} cout << '\n';}
void vout(vi v)							{fr(i, 0, (ll)v.S) {cout << v[i] << " ";} cout << endl;}
//----------------------------------------START-------------------------------------------
const ll maxN = (ll)(1 * 1e5 + 5 );
vii strip;
vii v;
float dist(pii a, pii b)
{
	return sqrt((b.ff - a.ff) * (b.ff - a.ff) + (b.ss - a.ss) * (b.ss - a.ss) );
}
float bruteForce(vii &v, ll n)
{
	float mini = FLT_MAX;
	for (ll i = 0; i < n; ++i)
		for (ll j = i + 1; j < n; ++j)
			if (dist(v[i], v[j]) < mini)
				mini = dist(v[i], v[j]);
	return mini;
}
int cmp(pii a, pii b)
{
	return (a.ss - b.ss);
}
float calc(vii & strip, ll d)
{
	ll n = strip.S;
	float mini = FLT_MAX;
	sort(all(strip), cmp);
	for (ll i = 0; i < strip.S; i++)
	{
		for (ll j = i + 1; j < n && strip[j].ss - strip[i].ss < d; j++)
		{
			mini = min(mini, dist(v[i], v[j]));
		}
	}
	return mini;
}
float closest(vii & v, ll st, ll end)
{
	if (v.S <= 3)return bruteForce(v, v.S);
	ll mid = (st + end) / 2;
	pii midp = v[mid];
	float dl = closest(v, st, mid);
	float dr = closest(v, mid + 1, end);
	float d = min(dl, dr);
	for (ll i = 0; i < v.S; i++)
	{
		if (midp.ff - v[i].ff < d)
		{
			strip.pb(v[i]);
		}
	}
	return min(d, calc(strip, d));
}
void solve()
{
	int a[10];
	cin >> a[0];
	cout << a[0];
}
int main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp1.txt", "r", stdin);
	freopen ("out1.txt", "w", stdout);
#endif
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

