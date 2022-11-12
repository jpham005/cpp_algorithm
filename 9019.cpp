#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

typedef queue<pair<int, string> > QueType;
typedef queue<pair<int, string> >::value_type QueValueType;

bool visit[10001];

void enqueue(QueType& que, const QueValueType& front) {
  int d, s, l, r;
  d = front.first * 2 % 10000;
  s = front.first - 1;
  if (s == -1) s = 9999;
  l = (front.first * 10 + front.first / 1000) % 10000;
  r = front.first / 10 + (front.first % 10) * 1000;

  if (!visit[d]) {
    visit[d] = true;
    que.push(QueValueType(d, front.second + 'D'));
  }

  if (!visit[s]) {
    visit[s] = true;
    que.push(QueValueType(s, front.second + 'S'));
  }

  if (!visit[l]) {
    visit[l] = true;
    que.push(QueValueType(l, front.second + 'L'));
  }

  if (!visit[r]) {
    visit[r] = true;
    que.push(QueValueType(r, front.second + 'R'));
  }
}

void solve() {
  memset(visit, 0, sizeof(visit));
  int start, target;
  cin >> start >> target;

  QueType que;
  que.push(QueValueType(start, string()));
  que.front().second.clear();
  visit[start] = true;
  while (!que.empty()) {
    size_t size = que.size();
    for (size_t i = 0; i < size; i++) {
      if (que.front().first == target) {
        cout << que.front().second << '\n';
        return;
      }

      enqueue(que, que.front());
      que.pop();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
