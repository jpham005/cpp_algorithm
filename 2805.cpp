#include <iostream>
#include <vector>

using namespace std;

typedef vector<size_t>::iterator iter;

vector<size_t> tree;

size_t n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    size_t curr;
    cin >> curr;

    tree.push_back(curr);
  }

  size_t result;
  size_t start = 0;
  size_t end = 1000000000;

  while (start <= end) {
    size_t sum = 0;
    size_t h = (start + end) / 2;

    for (iter it = tree.begin(); it != tree.end(); it++) {
      sum += (*it - h) * (*it > h);
    }

    if (sum >= m) {
      result = h;
      start = h + 1;
      continue;
    }

    if (sum < m) {
      end = h - 1;
      continue;
    }
  }

  cout << result << '\n';
}
