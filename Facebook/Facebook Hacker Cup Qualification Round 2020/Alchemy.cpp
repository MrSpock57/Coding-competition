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
ll a = 0, b = 0;
void solve(char ch) {
	if (ch == 'A')a++;
	else b++;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll test;
	cin >> test;
	ll t = 0;
	while (test--) {
		ll n;
		cin >> n;
		string str;
		cin >> str;
		stack<char>s;
		t++;
		for (ll i = 0; i < n; i++) {
			if (s.size() < 2) {
				s.push(str[i]);
			}
			else {
				s.push(str[i]);
				while (s.size() >= 3) {
					a = 0, b = 0;
					char ch1 = s.top();
					s.pop();
					char ch2 = s.top();
					s.pop();
					char ch3 = s.top();
					s.pop();
					solve(ch1);
					solve(ch2);
					solve(ch3);
					if (a == 0 || b == 0) {
						s.push(ch3);
						s.push(ch2);
						s.push(ch1);
						break;
					}
					if (a == 1 && b == 2)
						s.push('B');
					if (b == 1 && a == 2)
						s.push('A');
				}
			}
		}
		cout << "Case" << " " << "#" << t << ":" << " ";
		if (s.size() == 1)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}