#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int x, y;
bool field[50][50];

void erasePoint(int i, int j) {
  field[i][j] = false;
}

void eraseSingleField(int i, int j) {
  erasePoint(i, j);

  if (i > 0 && field[i - 1][j])
    eraseSingleField(i - 1, j);
  if (i + 1 < x && field[i + 1][j])
    eraseSingleField(i + 1, j);
  if (j > 0 && field[i][j - 1])
    eraseSingleField(i, j - 1);
  if (j + 1 < y && field[i][j + 1])
    eraseSingleField(i, j + 1);
}

void doTest() {
  int k;

  cin >> x >> y >> k;

  memset(field, false, sizeof(field));

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    field[a][b] = true;
  }

  int result = 0;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (field[i][j]) {
        result++;
        eraseSingleField(i, j);
      }
    }
  }

  cout << result << endl;
}

int main() {
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    doTest();
  }
}
