#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  set<int> s1;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    s1.insert(input);
  }

  int m;

  cin >> m;

  for (int i = 0; i < m; i++) {
    int input;
    cin >> input;

    if (s1.find(input) != s1.end())
      cout << "1\n";
    else
      cout << "0\n";
  }
}
