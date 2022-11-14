#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<pair<int, int> > VecType;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  VecType vec;

  int **map = new int*[n];
  for (int i = 0; i < n; i++) {
    map[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i || !map[j][i]) continue;

      for (int k = 0; k < n; k++) {
        if (!map[i][k]) continue;
        map[j][k] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }

  for (int i = 0; i < n; i++) {
    delete[] map[i];
  }

  delete[] map;
}
