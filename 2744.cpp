#include <string>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;

  cin >> str;

  for (string::iterator it = str.begin(); it != str.end(); it++) {
    if (islower(*it))
      *it = toupper(*it);
    else if (isupper(*it))
      *it = tolower(*it);
  }

  cout << str << '\n';
}
