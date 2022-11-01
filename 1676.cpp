#include <iostream>

using namespace std;

int n;

pair<int, int> memo[500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  if (n == 0) {
    cout << "0\n";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      memo[i - 1] = pair<int, int>(memo[i / 2 - 1].first + 1, memo[i / 2 - 1].second);
      continue;
    }

    if (i % 5 == 0) {
      memo[i - 1] = pair<int, int>(memo[i / 5 - 1].first, memo[i / 5 - 1].second + 1);
    }
  }

  pair<int, int> result(0, 0);

  for (int i = 0; i < n; i++) {
    result.first += memo[i].first;
    result.second += memo[i].second;
  }

  cout << min(result.first, result.second) << '\n';
}
