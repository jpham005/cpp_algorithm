#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> point;

bool IsInCircle(int x, int y, int r, point p) {
  return pow(x - p.first, 2) + pow(y - p.second, 2) < pow(r, 2);
}

void doTest() {
  int cnt;
  int result = 0;
  point start;
  point dest;

  cin >> start.first >> start.second >> dest.first >> dest.second >> cnt;

  for (int i = 0, x, y, r; i < cnt; i++) {
    cin >> x >> y >> r;

    bool start_in = IsInCircle(x, y, r, start);
    bool dest_in = IsInCircle(x, y, r, dest);

    if ((start_in + dest_in) && !(start_in * dest_in)) {
        result++;
    }
  }

  cout << result << endl;
}

int main() {
  int nTest;

  cin >> nTest;

  for (int i = 0; i < nTest; i++) {
    doTest();
  }
}
