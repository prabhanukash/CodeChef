#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e18+7)
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll nCrModpDP(ll n, ll r, ll p)
{

	ll C[r + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1;


	for (ll i = 1; i <= n; i++)
	{

		for (ll j = min(i, r); j > 0; j--)


			C[j] = (C[j] + C[j - 1]) % p;
	}
	return C[r];
}
ll nCrModpLucas(ll n, ll r, ll p)
{

	if (r == 0)
		return 1;


	ll ni = n % p, ri = r % p;


	return (nCrModpLucas(n / p, r / p, p) *
	        nCrModpDP(ni, ri, p)) % p;
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
	ll ans[t];
	for (ll tc = 0; tc < t; tc++)
	{

		ll n; cin >> n;
		ll x = (n * (n + 1)) / 2;
		if (x % 2 == 1)
		{
			ans[tc] = 0;
			//cout << 0 << '\n';
			//return 0;
		}
		else
		{
			ll sum = 0, c = 0;
			ll y = x / 2;
			for (ll i = n; i >= 1; i--)
			{
				sum += i;
				++c;
				if (y == sum)
				{
					ans[tc] = nCrModpDP(n - c, 2, mod) + nCrModpDP(c, 2, mod) + c;
					break;
					//cout << ans << '\n';
					//return ans;
				}
				else if (sum > y)
				{
					ans[tc] = c;
					break;
					//cout << c << '\n';
					//return c;
				}
			}
		}

	}
	for (ll tc = 0; tc < t; tc++)
	{
		cout << ans[tc] << endl;
	}
}