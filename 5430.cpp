#include <iostream>
#include <string>
#include <deque>

using namespace std;

int t;

size_t get_end(const string& str, int curr) {
  size_t i = curr;
  for (; str[i] != ',' && str[i] != ']'; i++);

  return i;
}

void solve() {
  string str;
  cin >> str;

  int n;
  cin >> n;

  deque<int> deq;
  bool is_front = true;

  string line;
  cin >> line;

  size_t curr = 1;
  size_t end;
  for (int i = 0; i < n; i++) {
    end = get_end(line, curr);
    int pushing = atoi(line.substr(curr, end - curr).c_str());
    deq.push_back(pushing);
    curr = end + 1;
  }

  for (string::iterator it = str.begin(); it != str.end(); it++) {
    if (*it == 'R') {
      is_front ^= true;
      continue;
    }

    if (*it == 'D') {
      if (deq.empty()) {
        cout << "error\n";
        return;
      }

      if (is_front) {
        deq.pop_front();
      } else {
        deq.pop_back();
      }
    }
  }

  if (is_front) {
    cout << '[';
    while (deq.size()) {
      cout << deq.front();
      deq.pop_front();
      if (deq.size())
        cout << ',';
    }
    cout << "]\n";
  } else {
    cout << '[';
    while (deq.size()) {
      cout << deq.back();
      deq.pop_back();
      if (deq.size())
        cout << ',';
    }
    cout << "]\n";
  }
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
