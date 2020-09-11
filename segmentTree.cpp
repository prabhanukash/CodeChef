#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e6)
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
//----------------------------------------FUNCTIONS---------------------------------------------------
ll gcd(ll x, ll y )						{if (y == 0) return x; return gcd(y, x % y);}
ll lcm(ll a, ll b)						{return (a * b) / gcd(a, b);}
ll logx(ll base, ll num)				{int cnt = 0; while (num != 1) {num /= base; ++cnt;} return cnt;}
vi vin(ll n)							{vi a(n); fr(i, 0, n) cin >> a[i]; return a;}
void out(vi a)							{for (int i = 0; i < (ll)a.S; i++) { cout << a[i] << " "; } cout << endl;}
void in(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void out(ll *a, ll n)					{fr(i, 0, n) {cout << a[i] << " ";} cout << '\n';}
void out1(vi v)							{fr(i, 0, (ll)v.S) {cout << v[i] << " ";} cout << endl;}
//----------------------------------------START--------------------------------------------------------
const ll maxN = (ll)(1 * 1e6 + 6 );
ll t[4 * maxN], a[maxN];
ll lazy[4 * maxN];
void build(ll a[], ll idx, ll tl, ll tr)
{
	if (tl == tr)t[idx] = a[tl];
	else
	{
		ll tm = (tl + tr) / 2;
		build(a, 2 * idx, tl, tm);
		build(a, 2 * idx + 1, tm + 1, tr);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}
}
ll qry(ll idx, ll tl, ll tr, ll l, ll r)
{
	if (lazy[idx] != 0)
	{
		ll dx = lazy[idx];
		lazy[idx] = 0;
		t[idx] += dx * (tr - tl + 1);
		if (tl != tr)
		{
			t[idx * 2] += dx;
			t[idx * 2 + 1] += dx;
		}
	}
	if (tl > r || tr < l)return 0;
	if (tl >= l && tr <= r )return t[idx];
	ll tm = (tl + tr) / 2;
	return qry(2 * idx, tl , tm, l, min(r, tm)) + qry(2 * idx + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(ll idx , ll tl, ll tr, ll l, ll r, ll val)
{
	if (lazy[idx] != 0)
	{
		ll dx = lazy[idx];
		lazy[idx] = 0;
		t[idx] += dx * (tr - tl + 1);
		if (tl != tr)
		{
			t[idx * 2] += dx;
			t[idx * 2 + 1] += dx;
		}
	}
	if (tl > r || tr < l)return;
	if (tl >= l && tr <= r)
	{
		ll dx = (tr - tl + 1) * val;
		t[idx] = dx;
		if (tl != tr)
		{
			lazy[2 * idx] = val;
			lazy[2 * idx + 1] = val;
		}
		ll tm = (tl + tr) / 2;
		update(idx * 2, tl, tm, l, r, val);
		update(idx * 2 + 1, tm + 1, tr, l, r, val);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}
}
void solve();
void solve()
{
	ll n, q;
	cin >> n >> q;
	//in(a, n);
	//build(a, 1, 0, n - 1);
	//out(t, 4 * n);
//	ll q;
///	cin >> q;
	fr(i, 0, q)
	{

		ll l, r, val;
		cin >> l >> r >> val;
		l--;
		r--;
		update(1, 0, n - 1, l, r, val) ;
	}
	out(t, n);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	fast();
	ll t = 1 ;
	//cin >> t;

	while (t--)
	{
		//	mset(ft, 0);
		solve();
	}
	return 0;
}