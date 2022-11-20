#include <iostream>

using namespace std;
int t, n;
int memo[12];

void solve() {
  cin >> n;

  for (int i = 5; i <= n; i++) {
    if (memo[i] == 0) {
      memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
  }

  cout << memo[n] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 4;
  memo[4] = 7;


  for (int i = 0; i < t; i++) {
    solve();
  }
}
