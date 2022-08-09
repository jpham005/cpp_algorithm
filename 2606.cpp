#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

void mark(int who, bool *com, vector<int> *graph) {
  if (com[who])
    return;

  com[who] = true;

  for (vector<int>::iterator it = graph[who].begin(); it != graph[who].end(); it++) {
    mark(*it, com, graph);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  vector<int> graph[n];

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  bool com[n];
  memset(com, 0, sizeof(com));

  mark(0, com, graph);

  int result = 0;

  for (int i = 0; i < n; i++) {
    if (com[i])
      result++;
  }

  cout << result - 1 << "\n";
}
