#include <iostream>
#include <queue>

using namespace std;

int n, m;
int box[1000][1000];
bool visit[1000][1000];
queue<pair<int, int> > que;

void enqueue() {
  int i = que.front().first;
  int j = que.front().second;

  if (i - 1 >= 0 && !visit[i - 1][j]) {
    visit[i - 1][j] = true;
    que.push(pair<int, int>(i - 1, j));
  }

  if (i + 1 < n && !visit[i + 1][j]) {
    visit[i + 1][j] = true;
    que.push(pair<int, int>(i + 1, j));
  }

  if (j - 1 >= 0 && !visit[i][j - 1]) {
    visit[i][j - 1] = true;
    que.push(pair<int, int>(i, j - 1));
  }

  if (j + 1 < m && !visit[i][j + 1]) {
    visit[i][j + 1] = true;
    que.push(pair<int, int>(i, j + 1));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  bool done = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];
      if (box[i][j] == 1) {
        visit[i][j] = true;
        que.push(pair<int, int>(i, j));
      }

      if (box[i][j] == -1)
        visit[i][j] = true;

      if (box[i][j] == 0) {
        done = false;
      }
    }
  }

  if (done) {
    cout << "0\n";
    return 0;
  }

  int cnt = 0;
  while (!que.empty()) {
    queue<pair<int, int> >::size_type size = que.size();
    for (queue<pair<int, int> >::size_type i = 0; i < size; i++) {
      enqueue();
      que.pop();
    }

    if (que.empty())
      break;
    cnt++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visit[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  }

  cout << cnt << '\n';
}
