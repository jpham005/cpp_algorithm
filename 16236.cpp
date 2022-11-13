#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Map {
public:
  typedef pair<int, int> CoordType;

private:
  int _mapData[20][20];
  int _mapSize;
  vector<CoordType> _target;
  int _sharkSize;
  int _eaten;
  CoordType _sharkPos;
  bool _visit[20][20];
  int _time;

  void setTarget() {
    _target.clear();

    for (int i = 0; i < _mapSize; i++) {
      for (int j = 0; j < _mapSize; j++) {
        if (_mapData[i][j] != 0 && _mapData[i][j] < _sharkSize) {
          _target.push_back(CoordType(i, j));
        }
      }
    }
  }

public:
  Map(): _sharkSize(2), _eaten(0), _time(0) {
    cin >> _mapSize;
    memset(_mapData, 0, sizeof(_mapData));

    for (int i = 0; i < _mapSize; i++) {
      for (int j = 0; j < _mapSize; j++) {
        cin >> _mapData[i][j];
        if (_mapData[i][j] == 9) {
          _sharkPos.first = i;
          _sharkPos.second = j;
          _mapData[i][j] = 0;
        }
      }
    }

    _target.reserve(_mapSize * _mapSize);
  }

  ~Map() {}

  const vector<CoordType>& getTarget() { setTarget(); return _target; }

  void eatTarget() {
    setTarget();

    queue<CoordType> que;

    memset(_visit, 0 ,sizeof(_visit));
    que.push(_sharkPos);
    _visit[_sharkPos.first][_sharkPos.second] = true;
    int elapsed = 0;

    bool isEnd = false;
    vector<pair<CoordType, int> > result;
    while (!que.empty()) {
      size_t size = que.size();
      for (size_t i = 0; i < size; i++) {
        CoordType curr = que.front();

        if (find(_target.begin(), _target.end(), curr) != _target.end()) {
          result.push_back(pair<CoordType, int>(curr, elapsed));
          isEnd = true;

//          cout << "y: " << curr.first << " x: " << curr.second << " el: " << elapsed << " sz: " << _sharkSize << '\n';
        }

//        enqueue();
        if (curr.first - 1 >= 0 && !_visit[curr.first - 1][curr.second] && _mapData[curr.first - 1][curr.second] <= _sharkSize) {
          _visit[curr.first - 1][curr.second] = true;
          que.push(CoordType(curr.first - 1, curr.second));
        }

        if (curr.second - 1 >= 0 && !_visit[curr.first][curr.second - 1] && _mapData[curr.first][curr.second - 1] <= _sharkSize) {
          _visit[curr.first][curr.second - 1] = true;
          que.push(CoordType(curr.first, curr.second - 1));
        }

        if (curr.second + 1 < _mapSize && !_visit[curr.first][curr.second + 1] && _mapData[curr.first][curr.second + 1] <= _sharkSize) {
          _visit[curr.first][curr.second + 1] = true;
          que.push(CoordType(curr.first, curr.second + 1));
        }

        if (curr.first + 1 < _mapSize && !_visit[curr.first + 1][curr.second] && _mapData[curr.first + 1][curr.second] <= _sharkSize) {
          _visit[curr.first + 1][curr.second] = true;
          que.push(CoordType(curr.first + 1, curr.second));
        }

        que.pop();

      }
      if (isEnd) {
        break;
      }

      elapsed++;
    }

    vector<pair<CoordType, int> >::iterator dest = result.end();
    CoordType final;
    final.first = 2147;
    final.second = 23123;
    for (vector<pair<CoordType, int> >::iterator it = result.begin(); it != result.end(); it++) {
      if (it->first.first < final.first) {
        dest = it;
        final = it->first;
      } else if (it->first.first == final.first && it->first.second < final.second) {
        dest = it;
        final = it->first;
      }
    }

    if (dest == result.end()) {
      cout << "0\n";
      exit(0);
    };

    _time += dest->second;
    _mapData[dest->first.first][dest->first.second] = 0;
    _sharkPos = dest->first;
    _eaten++;

    if (_eaten == _sharkSize) {
      _sharkSize++;
      _eaten = 0;
    }
  }

  const int& getTime() const { return _time; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Map map;

  while (!map.getTarget().empty()) {
    map.eatTarget();
  }

  cout << map.getTime() << '\n';
}
