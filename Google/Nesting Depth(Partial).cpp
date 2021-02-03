#include<bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin >> test;
	for (int k = 1; k <= test; k++) {
		string s;
		cin >> s;
		string res = "";
		int one = 0;
		for (int i = 0; i < int(s.size()); i++) {
			if (s[i] == '1') {
				if (one == 0) {
					res += '(';
				}
				res += '1';
				one++;
			}
			if (s[i] == '0') {
				if (one != 0) {
					res += ')';
					one = 0;
				}
				res += '0';
			}
		}
		if (s[s.size() - 1] == '1')
			res += ')';
		cout << "Case " << "#" << k << ":" << " " << res << endl;
	}
}



