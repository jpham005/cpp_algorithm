#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, b;

  cin >> n >> m >> b;

  int size = n * m;

  int map[size];

  for (int i = 0; i < size; i++) {
    cin >> map[i];
  }

  sort(&map[0], &map[size]);

  int result = INT_MAX;
  int last = -1;
  int height = 0;
  for (; height <= 256; height++) {
    int cnt = 0;
    int curr_block = b;

    for (int i = 0; i < size; i++) {
      if (map[size - i - 1] < height) {
        if (curr_block + map[size - i - 1] < height) {
          cnt = INT_MAX;
          break;
        }

        curr_block -= height - map[size - i - 1];
        cnt += height - map[size - i - 1];
      } else if (map[size - i - 1] > height) {
        cnt += (map[size - i - 1] - height) * 2;
        curr_block += map[size - i - 1] - height;
      }
    }

    if (cnt <= result) {
      if (height > last) {
        result = cnt;
        last = height;
      }
    }
  }

  cout << result << ' ' << last << '\n';
}
