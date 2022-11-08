#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <vector>

using namespace std;

size_t n, m;

void skip_o(const char* str, int& i) {
  while (str[i] && str[i] != 'I')
    i++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  char str[m + 1];

  cin >> str;
  str[m] = 0;

  int cnt = 0;

  int i = 0;
  skip_o(str, i);

  vector<int> vec;

  int target_len = n * 2 + 1;
  bool flag;
  while (str[i]) {
    flag = false;
    i++;
    int sub_len = 1;
    while (str[i]) {
      if ((!flag && str[i] != 'O') || (flag && str[i] != 'I')) {
        break;
      }

      flag ^= true;
      sub_len++;
      i++;
    }

    if (sub_len >= target_len) {
      vec.push_back(sub_len);
    }
    skip_o(str, i);
  }

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    while (*it >= target_len) {
      *it -= 2;
      cnt++;
    }
  }

  cout << cnt << '\n';
}
