#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<pair<int, int> > que;
int n, m;
int map[100][100];
int cnt = 0;

bool visited[100][100];

void enqueue() {

  if (que.front().first == m - 1 && que.front().second == n - 1) {
    cout << cnt + 1 << '\n';
    exit(0);
  }

  if (que.front().first + 1 < m && !visited[que.front().second][que.front().first + 1] && map[que.front().second][que.front().first + 1] == 1) {
    visited[que.front().second][que.front().first + 1] = true;
    que.push(pair<int, int>(que.front().first + 1, que.front().second));
  }

  if (que.front().first - 1 >= 0 && !visited[que.front().second][que.front().first - 1] && map[que.front().second][que.front().first - 1] == 1) {
    visited[que.front().second][que.front().first - 1] = true;
    que.push(pair<int, int>(que.front().first - 1, que.front().second));
  }

  if (que.front().second + 1 < n && !visited[que.front().second + 1][que.front().first] && map[que.front().second + 1][que.front().first] == 1) {
    visited[que.front().second + 1][que.front().first] = true;
    que.push(pair<int, int>(que.front().first, que.front().second + 1));
  }

  if (que.front().second - 1 >= 0 && !visited[que.front().second - 1][que.front().first] && map[que.front().second - 1][que.front().first] == 1) {
    visited[que.front().second - 1][que.front().first] = true;
    que.push(pair<int, int>(que.front().first, que.front().second - 1));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    for (int j = 0; j < m; j++) {
      map[i][j] = str[j] - '0';
    }
  }

  que.push(pair<int, int>(0, 0));
  visited[0][0] = true;

  while (!que.empty()) {
    queue<pair<int, int> >::size_type size = que.size();
    for (queue<pair<int, int> >::size_type i = 0; i < size; i++) {
      enqueue();
      que.pop();
    }

    cnt++;
  }
}
