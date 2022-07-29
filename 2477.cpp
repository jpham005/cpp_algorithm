#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  int n;

  cin >> n;

  pair<int, int> num[6];
  memset(num, 0, sizeof(num));

  for (int i = 0, i1, i2; i < 6; i++) {
    cin >> i1 >> i2;

    num[i] = make_pair(i1, i2);
  }

  vector<int> longSpan;
  vector<int> shortSpan;

  for (int i = 0; i < 6; i++) {
    if (num[i].first == num[(i + 2) % 6].first) {
      shortSpan.push_back(num[(i + 1) % 6].second);
      longSpan.push_back(num[(i + 4) % 6].second);
    }
  }

  cout << (longSpan[0] * longSpan[1] - shortSpan[0] * shortSpan[1]) * n << endl;
}
