#include <iostream>
#include <cstring>

using namespace std;

long long n, t;
long long memo[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  memset(memo, 0, sizeof(memo));
  memo[1] = 1;
  memo[2] = 1;
  memo[3] = 1;
  memo[4] = 2;
  memo[5] = 2;

  for (long long j = 0; j < t; j++) {
    cin >> n;
    for (long long i = 6; i <= n; i++) {
      if (memo[i] == 0) {
        memo[i] = memo[i - 1] + memo[i - 5];
      }
    }

    cout << memo[n] << '\n';
  }
}
