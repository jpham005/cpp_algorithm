#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n, m;

  cin >> n >> m;

  set<string> set1;
  set<string> set2;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    set1.insert(str);
  }

  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    set2.insert(str);
  }

  set<string> result;

  for (
    set<string>::iterator it1 = set1.begin(), it2 = set2.begin();
    it1 != set1.end() && it2 != set2.end();
  ) {
    if (*it1 == *it2) {
      result.insert(*it1);
      it1++;
      it2++;
    }
    else if (*it1 > *it2)
      it2++;
    else
      it1++;
  }

  cout << result.size() << "\n";

  for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
    cout << *it << "\n";
  }
}
