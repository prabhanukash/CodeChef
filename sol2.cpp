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
#define vb vector<bool>
#define vs vector<string>
#define psi pair<string,ll>
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
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
vi vin(ll n)							   {vi a(n); fr(i, 0, n) cin >> a[i]; return a;}
void out(vi a)							   {for (int i = 0; i < (ll)a.S; i++) { cout << a[i] << " "; } cout << endl;}
void in0(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void in1(ll *a, ll n)        			{for (ll i = 1; i <= n; i++)cin >> a[i];}
void out0(ll *a, ll n)					{fr(i, 0, n) {cout << a[i] << " ";} cout << '\n';}
void out1(ll *a, ll n)					{fr(i, 1, n + 1) {cout << a[i] << " ";} cout << '\n';}
void outv(vi v)							{fr(i, 0, (ll)v.S) {cout << v[i] << " ";} cout << endl;}
//----------------------------------------START--------------------------------------------------------
const ll maxN = (ll)(1 * 1e5 + 5 );
ll a[maxN], T[maxN], n, q;
void update(ll i, ll val)
{
	for (i + 1; i <= n + 1; i += (i & -i))
	{
		T[i] += val;
	}
}
ll qry(ll i)
{
	ll ans = 0;
	for (i + 1; i; i -= (i & -i))
	{
		ans += T[i];
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	fast();
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		update(i, a[i]);
	}
	cin >> q;
	while (q--)
	{
		ll l, r;
		cin >> l >> r;
		cout << qry(r) - qry(l - 1) << '\n';
	}

}