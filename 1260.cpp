#include <iostream>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

int n, m, v;

bool dots[1000];
set<int> lines[1000];
queue<int> que;

void dfs(int var) {
  for (int i = 0; i < n; i++) {
    if (!dots[i] && (lines[var].find(i) != lines[var].end())) {
      cout << ' ' << i + 1;
      dots[i] = true;
      dfs(i);
    }
  }
}

void enqueue(int var) {
  for (int i = 0; i < n; i++) {
    if (!dots[i] && (lines[var].find(i) != lines[var].end())) {
      cout << ' ' << i + 1;
      dots[i] = true;
      que.push(i);
    }
  }
}

void bfs() {
  while (!que.empty()) {
    queue<int>::size_type size = que.size();
    for (queue<int>::size_type i = 0; i < size; i++) {
      enqueue(que.front());
      que.pop();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    lines[a - 1].insert(b - 1);
    lines[b - 1].insert(a - 1);
  }

  cout << v;
  dots[v - 1] = true;
  dfs(v - 1);
  cout << '\n';

  cout << v;
  bzero(dots, sizeof(bool) * n);
  dots[v - 1] = true;
  enqueue(v - 1);
  bfs();
  cout << '\n';
}

