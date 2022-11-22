#include <iostream>

using namespace std;

int memo[50001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  memo[1] = 1;
  for (int i = 2; i <= n; i++) {
    int prev = 5;
    for (int j = 1; j * j <= i; j++) {
      if (i == j * j) {
        prev = 0;
        break;
      }

      if (memo[i - j * j] < prev) {
        prev = memo[i - j * j];
      }
    }

    memo[i] = prev + 1;
  }

  cout << memo[n] << '\n';
}
