#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  multiset<int> set;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    set.insert(a);
  }

  pair<int, int> result;
  result.first = 0;
  result.second = 0;

  for (multiset<int>::iterator it = set.begin(); it != set.end(); it++) {
    result.first += result.second + *it;
    result.second += *it;
  }

  cout << result.first << endl;
}
