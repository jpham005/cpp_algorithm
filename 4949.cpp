#include <stack>
#include <iostream>
#include <string>

using namespace std;

bool check_valid(const string& str) {
  stack<char> checker;

  for (std::size_t i = 0; i < str.size(); i++) {
    if (str[i] == '(')
      checker.push('(');
    if (str[i] == '[')
      checker.push('[');

    if (str[i] == ')') {
      if (checker.empty() || checker.top() != '(')
        return false;
      checker.pop();
    }

    if (str[i] == ']') {
      if (checker.empty() || checker.top() != '[')
        return false;
      checker.pop();
    }
  }

  return checker.empty();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;

  while (true) {
    getline(cin, str, '.');

    if (str.size() == 0 || str == "\n")
      break;

    check_valid(str) ? cout << "yes\n" : cout << "no\n";
  }
}
