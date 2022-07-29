#include <iostream>
#include <vector>

#include <cmath>

using namespace std;

typedef pair<int, int> point;
typedef vector<point> playerList;

bool IsInCircle(point c, int r, point p) {
  return pow(c.first - p.first, 2) + pow(c.second - p.second, 2) <= pow(r, 2);
}

void doTest() {
  point rec, c1, c2;
  int w, h, r, cnt;

  cin >> w >> h >> rec.first >> rec.second >> cnt;
  r = h / 2;

  c1.first = rec.first;
  c1.second = rec.second + h / 2;
  c2.first = rec.first + w;
  c2.second = rec.second + h / 2;

  playerList p;

  for (int i = 0; i < cnt; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back(playerList::value_type(x, y));
  }

  int result = 0;

  for (playerList::iterator it = p.begin(); it != p.end(); it++) {
    if (
      IsInCircle(c1, r, *it)
      || IsInCircle(c2, r, *it)
      || ((it->second >= rec.second && it->second <= rec.second + h) && (it->first >= rec.first && it->first <= rec.first + w))
    )
      result++;
  }

  cout << result << endl;
}

int main() {
  doTest();
}
