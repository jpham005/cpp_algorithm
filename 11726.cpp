#include <iostream>

using namespace std;

int n;
int memo[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  memo[1] = 1;
  memo[2] = 2;

  for (int i = 3; i <= n; i++) {
    memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
  }

  cout << memo[n] << '\n';
}
