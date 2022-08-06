#include <iostream>
#include <set>

using namespace std;

class Myset {
private:
  int    _mask;

public:
  Myset() : _mask(0) {}
  ~Myset() {}

  void add(int t) {
    if (_mask & (1 << t))
      return;

    _mask |= 1 << t;
  }

  void remove(int t) {
    if (!(_mask & (1 << t)))
      return;

    _mask &= ~(1 << t);
  }

  void check(int t) {
    cout << ((_mask & (1 << t)) != 0) << "\n";
  }

  void toggle(int t) {
    _mask ^= 1 << t;
  }

  void all() {
    for (int i = 1; i < 21; i++) {
      _mask |= 1 << i;
    }
  }

  void empty() {
    _mask = 0;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m;

  cin >> m;

  int x;
  string cmd;
  Myset s;
  for (int i = 0; i < m; i++) {
    cin >> cmd;

    if (cmd == "add") {
      cin >> x;
      s.add(x);
    } else if (cmd == "check") {
      cin >> x;
      s.check(x);
    } else if (cmd == "remove") {
      cin >> x;
      s.remove(x);
    } else if (cmd == "toggle") {
      cin >> x;
      s.toggle(x);
    } else if (cmd == "all") {
      s.all();
    } else {
      s.empty();
    }
  }
}
