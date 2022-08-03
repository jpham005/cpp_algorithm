#include <iostream>
#include <list>

using namespace std;

list<int> graph[10000];
bool node[10000];
int n, m;

void mark_linked(int start) {
  if (node[start] == true)
    return;

  node[start] = true;

  for (list<int>::iterator it = graph[start].begin(); it != graph[start].end(); it++) {
    mark_linked(*it);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    graph[a - 1].push_back(b);
  }

  int result = 0;

  for (int i = 0; i < n; i++) {
    if (node[i] == false) {
      mark_linked(i);
      result++;
    }
  }

  cout << result << endl;
}
