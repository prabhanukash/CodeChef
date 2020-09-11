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
const ll MAXN = (ll)(1 * 1e6 + 5 ), level = 22;
bool cmp(pii a, pii b)
{
	if (a.ff == b.ff)return (a.ss > b.ss);
	return a.ff < b.ff;
}
void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	fr(i, 0, n)cin >> a[i];
	vi v;
	ll cnt = 0;
	fr(i, 0, n )
	{
		if (a[i] == 0)cnt++;
		else
		{
			if (cnt != 0)v.pb(cnt);
			cnt = 0;
		}
	}
	sort(all(v));
	//fr(i, 0, v.S)cout << v[i] << " ";
	if (v[v.S - 1 ] % 2)cout << "Yes\n";
	else cout << "No\n";
	//cout << '\n';
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen ("inp4.txt", "r", stdin);
	freopen ("out4.txt", "w", stdout);
#endif
	fast();

	ll t = 1;
	cin >> t;
	//sieve(1e7 + 5);
	fr(i, 0, t)
	{
		solve();
		//cout << '\n';
	}
}

