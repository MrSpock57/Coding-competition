#include<bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int k = 1; k <= test; k++) {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>>v;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      v.push_back(make_pair(make_pair(l, r), i));
    }
    sort(v.begin(), v.end());
    int f = -1, s = -1;
    string res = "";
    int l = 0;
    for (int i = 0; i < int(v.size()); i++) {
      int a = v[i].first.first;
      if (a >= f) {
        res += 'C';
        f = v[i].first.second;
      }
      else if (a >= s) {
        res += 'J';
        s = v[i].first.second;
      }
      else {
        l = 1;
        break;
      }
    }
    vector<pair<int, char>>v1;
    for (int i = 0; i < v.size(); i++) {
      int t = v[i].second;
      char ch = res[i];
      v1.push_back(make_pair(t, ch));
    }
    sort(v1.begin(), v1.end());
    string fina = "";
    for (auto k : v1) {
      fina += k.second;
    }
    if (l == 1)
      fina = "IMPOSSIBLE";
    cout << "Case " << "#" << k << ":" << " " << fina << endl;
  }
}



