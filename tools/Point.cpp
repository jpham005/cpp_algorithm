#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
  int x;
  int y;

  void readPoint() {
    cin >> x >> y;
  }
};

typedef vector<Point> PointVector;

template <typename T>
void readPoint(PointVector& vec, const T& n) {

  for (T i = 0; i < n; i++) {
    Point p;
    p.readPoint();
    vec.push_back(p);
  }
}
