#include <iostream>
#include <queue>
#include <climits>
#include <unistd.h>

using namespace std;

int n, k;

bool memo[200002];

void enqueue(queue<pair<int, int> >& que) {
  if (que.front().first > 0 && !memo[que.front().first - 1]) {
    que.push(pair<int, int>(que.front().first - 1, que.front().second + 1));
  }

  if (que.front().first * 3 < k * 2 && que.front().first && !memo[que.front().first * 2])
    que.push(pair<int, int>(que.front().first * 2, que.front().second + 1));

  if (que.front().first < k && !memo[que.front().first + 1]) {
    que.push(pair<int, int>(que.front().first + 1, que.front().second + 1));
  }

  memo[que.front().first] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  queue<pair<int, int> > que;

  que.push(pair<int, int>(n, 0));
  memo[n] = true;

  int result = INT_MAX;

  while (!que.empty()) {
    queue<pair<int, int> >::size_type size = que.size();

    for (queue<pair<int, int> >::size_type i = 0; i < size; i++) {
      if (que.front().first == k && que.front().second < result) {
        result = que.front().second;
        que.pop();
        continue;
      }

      enqueue(que);
      que.pop();
    }
  }

  cout << result << '\n';
}
