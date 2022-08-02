#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool isdigit_string(const string& str) {
  for (int i = 0; i < (int)str.size(); i++) {
    if (!isdigit(str[i]))
      return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<string> vec;
  map<string, int> map;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    vec.push_back(str);
    map.insert(make_pair(str, i + 1));
  }

  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;

    if (isdigit_string(str)) {
      cout << vec[atoi(str.c_str()) - 1] << "\n";
    } else {
      cout << map.find(str)->second << "\n";
    }
  }
}
