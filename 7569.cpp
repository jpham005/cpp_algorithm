#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct coord {
  int x;
  int y;
  int z;
} coord;

queue<coord> que;

int n, m, h;

int box[100][100][100];
bool visit[100][100][100];

void enqueue() {
  coord curr = que.front();
  int x = curr.x;
  int y = curr.y;
  int z = curr.z;

  if (x - 1 >= 0 && !visit[z][y][x - 1]) {
    coord temp = curr;
    visit[temp.z][temp.y][temp.x - 1] = true;
    temp.x -= 1;
    que.push(temp);
  }

  if (x + 1 < m && !visit[z][y][x + 1]) {
    coord temp = curr;
    visit[curr.z][curr.y][curr.x + 1] = true;
    curr.x += 1;
    que.push(curr);
    curr = temp;
  }

  if (y - 1 >= 0 && !visit[z][y - 1][x]) {
    coord temp = curr;
    visit[curr.z][curr.y - 1][curr.x] = true;
    curr.y -= 1;
    que.push(curr);
    curr = temp;
  }

  if (y + 1 < n && !visit[z][y + 1][x]) {
    coord temp = curr;
    visit[curr.z][curr.y + 1][curr.x] = true;
    curr.y += 1;
    que.push(curr);
    curr = temp;
  }

  if (z - 1 >= 0 && !visit[z - 1][y][x]) {
    coord temp = curr;
    visit[curr.z - 1][curr.y][curr.x] = true;
    curr.z -= 1;
    que.push(curr);
    curr = temp;
  }

  if (z + 1 < h && !visit[z + 1][y][x]) {
    coord temp = curr;
    visit[curr.z + 1][curr.y][curr.x] = true;
    curr.z += 1;
    que.push(curr);
    curr = temp;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> box[i][j][k];
        if (box[i][j][k] != 0) {
          visit[i][j][k] = true;
        }

        if (box[i][j][k] == 1) {
          coord start;
          start.x = k;
          start.y = j;
          start.z = i;
          que.push(start);
        }
      }
    }
  }

  if (que.empty()) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
          if (!visit[i][j][k]) {
            cout << "-1\n";
            return 0;
          }
        }
      }
    }
    cout << "0\n";
    return 0;
  }

  int cnt = 0;
  while (!que.empty()) {
    queue<coord>::size_type size = que.size();
    for (queue<coord>::size_type i = 0; i < size; i++) {
      enqueue();
      que.pop();
    }

    if (que.empty())
      break;
    cnt++;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (!visit[i][j][k]) {
          cout << "-1\n";
          return 0;
        }
      }
    }
  }

  cout << cnt << '\n';
}
