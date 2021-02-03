#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
vector<ll>adj[60];
bool vis[60];
void bfs(ll i) {
	vis[i] = true;
	queue<ll>q;
	q.push(i);
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (auto k : adj[v]) {
			if (!vis[k]) {
				vis[k] = true;
				q.push(k);
			}
		}
	}
}
void clear() {
	for (ll i = 0; i < 60; i++) {
		vis[i] = false;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll  test;
	cin >> test;
	ll t = 0;
	while (test--) {
		t++;
		ll n;
		cin >> n;
		string s1, s2;
		cin >> s1;
		cin >> s2;
		for (ll i = 0; i < n; i++) {
			if (s1[i] == 'Y' && s2[i + 1] == 'Y' && i + 1 < n) {
				adj[i + 1].pb(i);
			}
			if (s1[i] == 'Y' && s2[i - 1] == 'Y' && i - 1 >= 0) {
				adj[i - 1].pb(i);
			}
		}
		vector<vector<char>>dp(n + 1, vector<char>(n + 1));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				dp[i][j] = 'N';
			}
		}
		for (ll i = 0; i < n; i++) {
			clear();
			bfs(i);
			for (ll j = 0; j < 55; j++) {
				if (vis[j] == true)
					dp[i][j] = 'Y';
			}
		}
		cout << "Case" << " " << "#" << t << ":" << endl;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				cout << dp[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < 60; i++) {
			adj[i].clear();
		}
	}
}