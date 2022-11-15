#include <iostream>
#include <map>

using namespace std;

typedef map<string, int> MapType;

void solve() {
  MapType m;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str >> str;
    MapType::iterator found = m.find(str);
    if (found != m.end()) {
      m[str]++;
      continue;
    }

    m.insert(pair<string, int>(str, 1));
  }

  int result = 1;
  for (MapType::iterator it = m.begin(); it != m.end(); it++) {
    result *= it->second + 1;
  }

  cout << result - 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
    solve();
}
