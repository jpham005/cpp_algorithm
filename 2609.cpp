#include <iostream>

using namespace std;

int plz(int a, int b) {
  while (true) {
    int c = a % b;
    if (c != 0) {
      a = b;
      b = c;
    } else {
      return b;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  int result = plz(max(n, m), min(n, m));

  cout << result << "\n" << n / result * m / result * result << "\n";
}
