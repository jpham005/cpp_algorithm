#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[20][20];
int curr_size = 0;
int curr_i, curr_j;
vector<pair<int, int> >fish[5];
vector<pair<int, int> > available_fish;

vector<pair<int, int> >&& find_fish() {
  vector<pair<int, int> >curr;

  for (int i = curr_size; i >= 0; i--) {
    curr.insert(fish[i].begin(), fish[i].end());
  }

  return curr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 0)
        continue;

      if (map[i][j] <= 2) {
        fish[0].push_back(pair<int, int>(i, j));
        continue;
      }

      if (map[i][j] == 3) {
        fish[1].push_back(pair<int, int>(i, j));
        continue;
      }

      if (map[i][j] == 4) {
        fish[2].push_back(pair<int, int>(i, j));
        continue;
      }

      if (map[i][j] == 5) {
        fish[3].push_back(pair<int, int>(i, j));
        continue;
      }

      if (map[i][j] == 6) {
        fish[4].push_back(pair<int, int>(i, j));
        continue;
      }

      if (map[i][j] == 9) {
        curr_i = i;
        curr_j = j;
        continue;
      }
    }
  }

  int time = 0;

  while (true) {
    vector<pair<int, int> > target = find_fish();

    if (target.empty()) {
      cout << time << '\n';
      return 0;
    }

    queue<pair<int, int> > que;
    que.push(pair<int, int>(curr_i, curr_j));
    visit[curr_i][curr_j] = true;
    bool visit[20][20];
    memset(visit, 0, sizeof(visit));
    while (!que.empty()) {
      size_t size = que.size();
      for (size_t i = 0; i < size; i++) {
        int vi = que.front().first;
        int vj = que.front().second;

        for (size_t k = 0; k < target.size(); k++) {
          if (vi == target[k].first && vj == target[k].second) {
            curr_i = vi;
            curr_j = vj;
            if (map[vi][vj] <= 2) {
              fish[0].erase(find(fish[0].begin(), fish[0].end(), pair<int, int>(vi, vj)));
            } else {
              fish[map[vi][vj] - 2]
            }
            break;
          }
        }

        if (vi + 1 < n && !visit[vi + 1][vj]) {
          visit[vi + 1][vj] = true;
          que.push(pair<int, int>(vi + 1, vj));
        }

        if (vi - 1 >= 0 && !visit[vi - 1][vj]) {
          visit[vi - 1][vj] = true;
          que.push(pair<int, int>(vi - 1, vj));
        }

        if (vj + 1 < n && !visit[vi][vj + 1]) {
          visit[vi][vj + 1] = true;
          que.push(pair<int, int>(vi, vj + 1));
        }

        if (vj - 1 >= 0 && !visit[vi][vj - 1]) {
          visit[vi][vj - 1] = true;
          que.push(pair<int, int>(vi, vj - 1));
        }

        que.pop();
      }

      time++;
    }
  }
}
