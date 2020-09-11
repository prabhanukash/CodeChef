#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9+7)
#define mset(a,k) memset(a,k,sizeof(a))
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
#define vvii vector<vii>
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
void out(vi a)							{for (int i = 0; i < (ll)a.S; i++) { cout << a[i] << " "; } cout << endl;}
void in(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void out(ll *a, ll n)					{fr(i, 0, n) {cout << a[i] << " ";} cout << '\n';}
void out1(vi v)							{fr(i, 0, (ll)v.S) {cout << v[i] << " ";} cout << endl;}
const ll MAXN = (ll)(1 * 1e5 + 5 ), level = 22;
ll BLK;
ll a[MAXN];
ll F[320];
ll n;
void update(ll index, ll val)
{
	ll BLK = ceil(sqrt(n));
	ll idx = index / blocksize;
	F[idx] = min(val, F[idx]);
	a[index] = val;
}
ll getMin(ll l, ll r)
{
	//cout << l << " " << r << '\n';
	BLK = ceil(sqrt(n));
	ll LB = l / BLK;
	ll RB = r / BLK;
	//cout << LB << " " << RB << '\n';
	mapll m;
	ll mn = INT_MAX;
	if (LB == RB)
	{
		for (ll i = l; i <= r; i++)
		{
			m[a[i]]++;
		}
		//cout << mn << '\n';
	}
	else
	{

		for (ll i = l; i < (LB + 1)*BLK; i++)
		{
			m[a[i]]++;
		}
		for (ll i = (LB + 1); i < RB; i++)
		{
			m[a[i]]++;
		}
		for (ll i = RB * BLK; i <= r; i++)
		{
			m[a[i]]++;
		}
	}
	ll cnt = 0;
	for (auto it : m)
	{
		if (it.ff == it.ss)cnt++;
	}
	return cnt;
}
void solve()
{
	//ll n;
	cin >> n;
	//ll a[n];
	BLK = (ll)ceil(sqrt(n));
	//cout << BLK << '\n';
	//ll F[BLK];
//	for (ll i = 0; i < BLK; i++)F[i] = INT_MAX;
	in(a, n);
	ll mini;
	ll idx = -1;
	for (ll i = 0; i < n; i++)
	{
		//arr[i] = a[i];
		if (i % BLK == 0)
		{
			idx++;
			F[idx] = a[i];
		}
		//mini = min(mini, a[i]);
		F[idx] = min(F[idx], a[i]);
		//cout << F[idx] << " ";
	}
	//cout << '\n';
	/*	fr(i, 0, BLK)cout << F[i] << " ";
		cout << '\n';*/
	ll m;
	cin >> m;
	while (m--)
	{
		ll l, r;
		cin >> l >> r;
		//l--; r--;
		cout << getMin(l, r) << '\n';
	}
}
int main()
{

	/*#ifndef ONLINE_JUDGE
		freopen ("inp4.txt", "r", stdin);
		freopen ("out4.txt", "w", stdout);
	#endif*/
	fast();

	ll t = 1;
	//cin >> t;
	//sieve(1e7 + 5);
	fr(i, 0, t)
	{
		solve();
	}
}

