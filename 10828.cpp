#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  stack<int> s;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    int input;
    cin >> str;

    if (str == "push") {
      cin >> input;
      s.push(input);
    } else if (str == "top") {
      if (s.empty()) {
        cout << "-1\n";
      } else {
        cout << s.top() << "\n";
      }
    } else if (str == "size") {
      cout << s.size() << "\n";
    } else if (str == "pop") {
      if (s.empty()) {
        cout << "-1\n";
      }
      else {
        cout << s.top() << "\n";
        s.pop();
      }
    } else if (str == "empty") {
      cout << static_cast<int>(s.empty()) << "\n";
    }

    cin.clear();
  }
}
