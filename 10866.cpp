#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<int> d;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string str;
    int input;

    cin >> str;
    if (str == "push_back") {
      cin >> input;
      d.push_back(input);
    } else if (str == "push_front") {
      cin >> input;
      d.push_front(input);
    } else if (str == "back") {
      if (d.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << d.back() << "\n";
    } else if (str == "front") {
        if (d.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << d.front() << "\n";
    } else if (str == "size") {
      cout << d.size() << "\n";
    } else if (str == "empty") {
      cout << (int)d.empty() << "\n";
    } else if (str == "pop_front") {
      if (d.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << d.front() << "\n";
      d.pop_front();
    } else if (str == "pop_back") {
      if (d.empty()) {
        cout << "-1\n";
        continue;
      }

      cout << d.back() << "\n";
      d.pop_back();
    }
  }
}
