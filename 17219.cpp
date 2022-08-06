#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, string> m;

  int n1, n2;

  cin >> n1 >> n2;

  for (int i = 0; i < n1; i++) {
    string s1, s2;
    cin >> s1 >> s2;

    m[s1] = s2;
  }

  for (int i = 0; i < n2; i++) {
    string str;
    cin >> str;
    cout << m.find(str)->second << "\n";
  }
}
