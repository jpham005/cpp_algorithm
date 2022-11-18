#include <iostream>
#include <queue>

using namespace std;

typedef enum e_dir {
  EAST = 1 << 0,
  WEST = 1 << 1,
  SOUTH = 1 << 2,
  NORTH = 1 << 3
} e_dir;

typedef struct CoordType {
  int x;
  int y;
  e_dir dir;
} CoordType;

int map[101][101];
int visit[101][101];
int n, m;
queue<CoordType> que;

bool isOpposite(const e_dir& a, const e_dir& b) {
  return a + b == 3 || a + b == 7;
}

bool isOutbound(const CoordType& curr, const int& dx, const int& dy) {
  return (
    curr.x + dx <= 0
    || curr.x + dx > n
    || curr.y + dy <= 0
    || curr.y + dy > m
  );
}

void tryPush(const CoordType& curr, const int& dx, const int& dy, const e_dir& dir) {
  for (int i = 1; i <= 3; i++) {
    if (!isOutbound(curr, dx * i, dy * i) && map[curr.y + dy * i][curr.x + dx * i] == 1)
      return;

    if (isOutbound(curr, dx * i, dy * i) || (visit[curr.y + dy * i][curr.x + dx * i] & dir))
      continue;

    CoordType pushing = curr;
    pushing.x += dx * i;
    pushing.y += dy * i;
    que.push(pushing);
  }
}

void enqueue(const CoordType& front) {
  CoordType pushing = front;

  if (!(front.dir & (EAST | WEST)) && !(visit[front.y][front.x] & EAST)) {
    visit[front.y][front.x] |= EAST;
    pushing.dir = EAST;
    que.push(pushing);
  }

  if (!(front.dir & (EAST | WEST)) && !(visit[front.y][front.x] & WEST)) {
    visit[front.y][front.x] |= WEST;
    pushing.dir = WEST;
    que.push(pushing);
  }

  if (!(front.dir & (SOUTH | NORTH)) && !(visit[front.y][front.x] & SOUTH)) {
    visit[front.y][front.x] |= SOUTH;
    pushing.dir = SOUTH;
    que.push(pushing);
  }

  if (!(front.dir & (SOUTH | NORTH)) && !(visit[front.y][front.x] & NORTH)) {
    visit[front.y][front.x] |= NORTH;
    pushing.dir = NORTH;
    que.push(pushing);
  }

  switch (front.dir) {
    case EAST:
      tryPush(front, 1, 0, front.dir);
      break;
    case WEST:
      tryPush(front, -1, 0, front.dir);
      break;
    case SOUTH:
      tryPush(front, 0, 1, front.dir);
      break;
    case NORTH:
      tryPush(front, 0, -1, front.dir);
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  CoordType start;
  CoordType target;

  int temp;
  cin >> start.y >> start.x >> temp;
  start.dir = static_cast<e_dir>(1 << (temp - 1));
  cin >> target.y >> target.x >> temp;
  target.dir = static_cast<e_dir>(1 << (temp - 1));

  if (start.x == target.x && start.y == target.y) {
    if (start.dir == target.dir) {
      cout << "0\n";
      return 0;
    }

    if (isOpposite(start.dir, target.dir)) {
      cout << "2\n";
      return 0;
    }

    cout << "1\n";
    return 0;
  }

  que.push(start);
  visit[start.y][start.x] = start.dir;
  int cnt = 0;
  while (!que.empty() && !(que.front().x == target.x && que.front().y == target.y && que.front().dir == target.dir)) {
    size_t size = que.size();
    for (size_t i = 0; i < size; i++) {
      cout << que.front().y << ' ' << que.front().x << ' ' << que.front().dir << '\n';
      enqueue(que.front());
      que.pop();
    }

    cnt++;
  }

//  cout << que.front().y << ' ' << que.front().x << ' ' << que.front().dir << '\n';
  cout << cnt << '\n';
}
