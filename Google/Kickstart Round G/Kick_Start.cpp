#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	int c = 0;
	while (test--) {
		c++;
		string s;
		cin >> s;
		ll k = 0, st = 0;
		ll ans = 0;
		for (int i = 0; i < int(s.size()); i++) {
			if (i <= s.size() - 4) {
				string s1 = s.substr(i, 4);
				if (s1 == "KICK") {
					k++;
				}
			}
			if (i <= s.size() - 5) {
				string s1 = s.substr(i, 5);
				if (s1 == "START") {
					st++;
					ans += (k);
				}
			}
		}
		cout << "Case #" << c << ":" << " " << ans << endl;
	}
}