#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int map[100][100];
int n;
bool visit[100][100];
queue<pair<int, int> > que;

bool isSameColor(int a, int b, bool oops) {
  return a == b || (oops && ((a == 'R' && b == 'G') || (a == 'G' && b == 'R')));
}

void mark(const pair<int, int>& pos, bool oops) {
  if (pos.first - 1 >= 0 && !visit[pos.first - 1][pos.second]) {
    if (isSameColor(map[pos.first][pos.second], map[pos.first - 1][pos.second], oops)) {
      visit[pos.first - 1][pos.second] = true;
      mark(pair<int, int>(pos.first - 1, pos.second), oops);
    }
  }

  if (pos.first + 1 < n && !visit[pos.first + 1][pos.second]) {
    if (isSameColor(map[pos.first][pos.second], map[pos.first + 1][pos.second], oops)) {
      visit[pos.first + 1][pos.second] = true;
      mark(pair<int, int>(pos.first + 1, pos.second), oops);
    }
  }

  if (pos.second - 1 >= 0 && !visit[pos.first][pos.second - 1]) {
    if (isSameColor(map[pos.first][pos.second], map[pos.first][pos.second - 1], oops)) {
      visit[pos.first][pos.second - 1] = true;
      mark(pair<int, int>(pos.first, pos.second - 1), oops);
    }
  }

  if (pos.second + 1 < n && !visit[pos.first][pos.second + 1]) {
    if (isSameColor(map[pos.first][pos.second], map[pos.first][pos.second + 1], oops)) {
      visit[pos.first][pos.second + 1] = true;
      mark(pair<int, int>(pos.first, pos.second + 1), oops);
    }
  }
}

void huck(int a, int b, bool oops) {
  que = queue<pair<int, int> >();
  que.push(pair<int, int>(a, b));
  visit[a][b] = true;
  while (!que.empty()) {
    size_t size = que.size();
    for (size_t i = 0; i < size; i++) {
      pair<int, int> front = que.front();
      mark(front, oops);

      que.pop();
    }
  }
}

void solve(bool oops) {
  memset(visit, 0, sizeof(visit));
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visit[i][j])
        continue;

      huck(i, j, oops);
      cnt++;
    }
  }

  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;

    for (int j = 0; j < n; j++) {
      map[i][j] = str[j];
    }
  }

  solve(false);
  solve(true);
}
