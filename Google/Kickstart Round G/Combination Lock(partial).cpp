#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(vector<ll>&v, ll mid, ll w) {
	ll ans = 0;
	for (ll i = 0; i < ll(v.size()); i++) {
		ll nx = (abs(mid - v[i]));
		ll nx1 = ((abs(1 - v[i]) + abs(w - mid))) + 1;
		ll nx2 = (abs(w - v[i]) + abs(1 - mid)) + 1;
		ans += min({nx, nx1, nx2});
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test;
	cin >> test;
	ll c = 0;
	while (test--) {
		c++;
		ll n, w;
		cin >> n >> w;
		vector<ll>v(n);
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		ll avg = sum / n;
		ll ans = 1e18;
		ll y = avg - 1000;
		if (y < 0)y = 1;
		ll x = 1000 + avg;
		if (x > w)x = w;
		for (ll i = y; i <= x; i++) {
			ans = min(ans, solve(v, i, w));
		}
		cout << "Case #" << c << ":" << " " << ans << endl;
	}
}