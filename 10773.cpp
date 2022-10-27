#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int k;

  cin >> k;

  stack<int> nums;
  int sum = 0;

  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;

    if (n != 0) {
        nums.push(n);
        continue;
    }

    nums.pop();
  }

  while (!nums.empty()) {
    sum += nums.top();
    nums.pop();
  }

  cout << sum << '\n';
}
