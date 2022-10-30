#include <iostream>
#include <limits>

using namespace std;

int memo[1000000];
bool done[1000000];

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  memo[0] = 0;
  done[0] = true;

  for (int i = 1; i <= n; i++) {
    if (!done[i - 1]) {
      done[i - 1] = true;

      int result = numeric_limits<int>::max();
      int before;

      if (!(i % 3)) {
        before = memo[i / 3 - 1];
        if (before < result)
          result = before;
      }

      if (!(i % 2)) {
        before = memo[i / 2 - 1];
        if (before < result)
          result = before;
      }

      before = memo[i - 2];
      if (before < result)
        result = before;

      memo[i - 1] = result + 1;
      continue;
    }
  }

  cout << memo[n - 1] << '\n';
}
