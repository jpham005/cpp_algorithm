#include <iostream>
#include <set>

using namespace std;

multiset<int> mset;
int size;
int t, k;

void solve() {
  int n;

  cin >> n;

  mset.clear();
  for (int i = 0; i < n; i++) {
    char cmd;
    int target;

    cin >> cmd >> target;

    if (cmd == 'I') {
      mset.insert(target);
      continue;
    }

    if (cmd == 'D') {
      if (mset.empty())
        continue;

      if (target == 1) {
        mset.erase(--mset.end());
        continue;
      }

      mset.erase(mset.begin());
    }
  }

  if (mset.empty()) {
    cout << "EMPTY\n";
    return;
  }

  cout << *(--mset.end()) << ' ' << *(mset.begin()) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}
