#include <iostream>
#include <algorithm>

using namespace std;

int n;

int memo[300];
int stair[300];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> stair[i];
  }

  memo[0] = stair[0];
  memo[1] = stair[0] + stair[1];
  memo[2] = max(stair[0], stair[1]) + stair[2];

  for (int i = 3; i < n; i++) {
    memo[i] = max(memo[i - 3] + stair[i - 1] + stair[i], memo[i - 2] + stair[i]);
  }

  cout << memo[n - 1] << '\n';
}
