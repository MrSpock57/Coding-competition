#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test;
	cin >> test;
	ll c = 0;
	while (test--) {
		c++;
		ll n;
		cin >> n;
		ll nax = 0;
		vector<vector<ll>>v(n, vector<ll>(n));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				cin >> v[i][j];
				nax = max(nax, v[i][j]);
			}
		}
		vector<vector<ll>>dp(n, vector<ll>(n, 0));
		for (int i = 0; i < n; i++)dp[i][0] = v[i][0];
		for (int i = 0; i < n; i++)dp[0][i] = v[0][i];
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + v[i][j]);
				nax = max(nax, dp[i][j]);
			}
		}
		cout << "Case #" << c << ":" << " " << nax << endl;
	}
}










