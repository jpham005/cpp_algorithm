#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[25][25];
bool visit[25][25];
vector<int> vec;

void enqueue(queue<pair<int, int> >& que) {
  int i = que.front().first;
  int j = que.front().second;

  if (i + 1 < n && !visit[i + 1][j] && map[i + 1][j] == 1) {
    visit[i + 1][j] = true;
    que.push(pair<int, int>(i + 1, j));
  }

  if (i - 1 >= 0 && !visit[i - 1][j] && map[i - 1][j] == 1) {
    visit[i - 1][j] = true;
    que.push(pair<int, int>(i - 1, j));
  }

  if (j + 1 < n && !visit[i][j + 1] && map[i][j + 1] == 1) {
    visit[i][j + 1] = true;
    que.push(pair<int, int>(i, j + 1));
  }

  if (j - 1 >= 0 && !visit[i][j - 1] && map[i][j - 1] == 1) {
    visit[i][j - 1] = true;
    que.push(pair<int, int>(i, j - 1));
  }
}

void mark(int i, int j) {
  int cnt = 0;
  queue<pair<int, int> > que;

  que.push(pair<int, int>(i, j));
  visit[i][j] = true;
  while (!que.empty()) {
    queue<pair<int, int> >::size_type size = que.size();
    for (queue<pair<int, int> >::size_type i = 0; i < size; i++) {
      enqueue(que);
      que.pop();
      cnt++;
    }
  }

  vec.push_back(cnt);
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
      map[i][j] = str[j] - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visit[i][j] || map[i][j] == 0) {
        continue;
      }

      mark(i, j);
    }
  }

  sort(vec.begin(), vec.end());

  cout << vec.size() << '\n';

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    cout << *it << '\n';
  }
}
