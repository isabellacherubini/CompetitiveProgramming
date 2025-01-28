#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin >> n;
  int last = 100;
  cout << last << endl;
  int cur = 1;
  while (n) {
    cout << cur + 1 << " " << cur + 2 << endl;
    int second = -1;
    if (n%2 != 0) {
      second = last;
    }
    cout << cur + 3 << " " << second << endl;
    cout << cur + 3 << " " << -1 << endl;
    cur += 3;
    n /= 2;
  }
  while (cur <= last) {
    cout << "-1 -1\n";
    cur++;
  }
}