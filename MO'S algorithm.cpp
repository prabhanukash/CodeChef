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
ll BLK = 555;
ll a[MAXN];
ll q[MAXN];
ll F[MAXN];
ll cnt = 0;
struct qry
{
	ll l, ll r, ll idx;

};
bool cmp(qry a, qry b)
{
	if (a.l / BLK != b.l / BLK)
	{
		return a.l / BLK < b.l / BLK;
	}
	return a.r < b.r
}
void add(ll pos)
{
	F[a[pos]]++;
	if (F[a[pos]] == 1)cnt++;
}
void remove(ll pos)
{
	F[a[pos]]--;
	if (F[a[pos]] == 0)cnt--;
}
void solve()
{
	ll n;
	cin >> n;
	in(a, n);
	ll m;
	cin >> m;
	fr(i, 0, m)
	{
		ll l, r;
		cin >> l >> r;
		q[i].l = l;
		q[i].r = r;
		q[i].idx = i;
	}
	sort(q, q + m, cmp);
	fr(i, 0, m)
	{
		ll L = q[i].l;
		ll R = q[i].r;
		while (ML > L)
			ML-- , add(ML);

		while (MR < R)
			MR++ , add(MR);

		while (ML < L)
			remove(ML) , ML++;

		while (MR > R)
			remove(MR) , MR--;
		ans[q[i].idx] = cnt;
	}
	fr(i, 0, m)cout < ans[i] << '\n';
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen ("inp4.txt", "r", stdin);
	freopen ("out4.txt", "w", stdout);
#endif
	fast();

	ll t = 1;
	//cin >> t;
	//sieve(1e7 + 5);
	fr(i, 0, t)
	{
		solve();
	}
}

