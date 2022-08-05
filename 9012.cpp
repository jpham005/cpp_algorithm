#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int yeju = 0;
    string str;
    cin >> str;

    string::iterator it;
    for (it = str.begin(); it != str.end(); it++) {
      if (*it == '(')
        yeju++;
      else
        yeju--;
      if (yeju < 0) {
        break;
      }
    }

    if (it == str.end() && yeju == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
