#include <iostream>

using namespace std;

int n, r, c, result;

void solve(int x, int y, int size) {
  if (x == c && y == r) {
    cout << result << "\n";
    exit(0);
  }

  if (x <= c && c < x + size && y <= r && r < y + size) {
    solve(x, y, size >> 1);
    solve(x + (size >> 1), y, size >> 1);
    solve(x, y + (size >> 1), size >> 1);
    solve(x + (size >> 1), y + (size >> 1), size >> 1);
  } else {
    result += size * size;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> r >> c;

  solve(0, 0, 1 << n);
}
