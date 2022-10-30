#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

bool visited[100];
vector<int> line[100];

static void enque(queue<int>& que, int curr){
  for (vector<int>::iterator it = line[curr].begin(); it != line[curr].end(); it++) {
    if (!visited[*it]) {
      visited[*it] = true;
      que.push(*it);
    }
  }
}

static int bfs(int i) {
  queue<int> que;
  int ret = 0;
  int step = 1;

  visited[i] = true;
  enque(que, i);
  while (!que.empty()) {
    ret += que.size() * step++;

    queue<int>::size_type size = que.size();
    for (queue<int>::size_type j = 0; j < size; j++) {
      enque(que, que.front());
      que.pop();
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;


  for (int i = 0; i < m; i++) {
    int from, to;

    cin >> from >> to;

    line[from - 1].push_back(to - 1);
    line[to - 1].push_back(from - 1);
  }

  int result = numeric_limits<int>::max();
  int kbn;
  int winner;

  for (int i = 0; i < n; i++) {
    kbn = bfs(i);
    if (kbn < result) {
      result = kbn;
      winner = i;
    }
    bzero(visited, sizeof(bool) * n);
  }

  cout << winner + 1 << '\n';
}
