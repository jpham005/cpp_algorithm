#include <iostream>

using namespace std;

int n;
int paper[128][128];
int blue, white;

void solve(int y, int x, int curr) {
  for (int i = y; i < y + curr; i++) {
    for (int j = x; j < x +curr; j++) {
      if (paper[i][j] != paper[y][x]) {
        solve(y, x, curr / 2);
        solve(y + curr / 2, x, curr / 2);
        solve(y, x + curr / 2, curr / 2);
        solve(y + curr / 2, x + curr / 2, curr / 2);
        return;
      }
    }
  }

  if (paper[y][x] == 1) {
    blue++;
  } else {
    white++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }

  solve(0, 0, n);

  cout <<  white << '\n' << blue << '\n';
}
