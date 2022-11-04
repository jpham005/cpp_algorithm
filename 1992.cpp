#include <iostream>
#include <string>

using namespace std;

int n;
char arr[64 * 64 + 1];
string str;

int check(int start, int curr) {
  for (int i = 0; i < curr; i++) {
    for (int j = 0; j < curr; j++) {
      if (arr[start + i * n + j] != arr[start]) {
        return -1;
      }
    }
  }
  return arr[start];
}

void solve(int start, int curr) {
  int result = check(start, curr);
  if (result >= 0) {
    str.push_back(result);
    return;
  }

  str.push_back('(');
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      solve(start + i * curr / 2 * n + j * curr / 2, curr / 2);
    }
  }
  str.push_back(')');

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n * n; i++) {
    char c;
    cin >> c;
    arr[i] = c;
  }

  solve(1, n);

  cout << str << '\n';
}
