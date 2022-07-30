#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> line;

int k, n;

int getCount(int len) {
  int ret = 0;

  for (int i = 0; i < k; i++) {
    ret += line[i] / len;
  }

  return ret;
}

int search(long long start, long long end) {
  int cnt = getCount((end + start) / 2);

  if (start + 1 >= end) {
    if (getCount(end) >= n)
      return end;

    return start;
  }

  if (cnt < n)
    return search(start, (end + start) / 2);

  return search((end + start) / 2, end);
}

int main() {
  cin >> k >> n;

  for (int i = 0; i < k; i++) {
    int len;
    cin >> len;
    line.push_back(len);
  }

  cout << search(0, INT_MAX) << endl;
}
