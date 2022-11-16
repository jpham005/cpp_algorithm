#include <iostream>
#include <map>
#include <queue>

using namespace std;

int board[101];
bool visit[101];
map<int, int> ladder;
map<int, int> snake;
queue<int> que;
int cnt;

void pusher(int start) {
  if (start > 100) {
    return;
  }

  map<int, int>::iterator found = ladder.find(start);
  if (found != ladder.end()) {
    if (!visit[found->second]) {
      visit[found->second] = true;
      que.push(found->second);
    }
    return;
  }

  found = snake.find(start);
  if (found != snake.end()) {
    if (!visit[found->second]) {
      visit[found->second] = true;
      que.push(found->second);
    }
    return;
  }

  if (!visit[start]) {
    visit[start] = true;
    que.push(start);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;

    ladder.insert(pair<int, int>(start, end));
  }

  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;

    snake.insert(pair<int, int>(start, end));
  }

  que.push(1);

  while (!que.empty()) {
    size_t size = que.size();
    for (size_t i = 0; i < size; i++) {
      if (que.front() == 100) {
        cout << cnt << '\n';
        return 0;
      }

      for (int j = 1; j <= 6; j++) {
        pusher(que.front() + j);
      }

      que.pop();
    }

    cnt++;
  }
}
