#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll test;
	cin >> test;
	for (int c = 1; c <= test; c++) {
		ll n;
		cin >> n;
		int a[n][n];
		ll sum = 0;
		ll ans = 0;
		ll ans1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		set<ll>s, s1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s.insert(a[i][j]);
				s1.insert(a[j][i]);
				if (i == j)
					sum += a[i][j];
			}
			if (s.size() < n)
				ans++;
			if (s1.size() < n)
				ans1++;
			s.clear();
			s1.clear();
		}
		cout << "Case " << "#" << c << ":" << " " << sum << " " << ans << " " << ans1 << endl;
	}
}



