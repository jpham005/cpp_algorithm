#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef string::iterator iter;

int n, m;
bool blocked[10] = {0,};

bool check_block(int n) {
  string str = to_string(n);

  for (iter it = str.begin(); it != str.end(); it++) {
    if (blocked[(int)*it - '0']) {
      return false;
    }
  }

  return true;
}

void get_target(int& target) {
  int new_target = 999999999;
  int new_target2 = 999999999;

  for (int i = target - 1; i >= 0; i--) {
    if (check_block(i)) {
      new_target = i;
      break;
    }
  }

  for (int i = target; i <= target + abs(target - 100); i++) {
    if (check_block(i)) {
      new_target2 = i;
      break;
    }
  }

  int cnt1, cnt2;
  string str1, str2;

  str1 = to_string(new_target);
  str2 = to_string(new_target2);

  cnt1 = str1.length() + abs(new_target - target);
  cnt2 = str2.length() + abs(new_target2 - target);

  int cnt3 = abs(target - 100);

//  cout << str1 << ' ' << str2 << '\n';
//  cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';

  target = min(min(cnt1, cnt2), cnt3);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int curr;
    cin >> curr;

    blocked[curr] = true;
  }

  get_target(n);
  cout << n << '\n';
}
