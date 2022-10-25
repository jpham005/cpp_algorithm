#include <iostream>
#include <stack>
#include <unistd.h>

using namespace std;

char operation[400000];
int size;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin.tie(NULL);

  stack<int> container;

  int n;
  cin >> n;
  int target[n];
  int target_index = 0;
  int curr = 1;

  for (int i = 0; i < n; i++) {
    cin >> target[i];
  }

  for (int i = 1; i <= n; i++) {
    while (true) {
      if (container.empty() || container.top() < target[target_index]) {
        container.push(curr++);
        operation[size++] = '+';
        operation[size++] = '\n';
        continue;
      }

      if (!container.empty() && container.top() == target[target_index]) {
        target_index++;
        container.pop();
        operation[size++] = '-';
        operation[size++] = '\n';
        break;
      }

      if ((container.empty() && curr > target[target_index]) || container.top() > target[target_index]) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  write(1, operation, size);
}
