#include <queue>
#include <iostream>

using namespace std;

static void solve() {
  queue<pair<int, int> > docs;

  int n, target;
  cin >> n >> target;

  for (int i = 0; i < n; i++) {
    int prior;
    cin >> prior;

    docs.push(pair<int, int>(i, prior));
  }

  int curr_prior = 9;
  int result = 1;
  int break_index = n;
  int temp = 0;

  while (true) {
    const pair<int, int> curr_doc = docs.front();
    docs.pop();

    if (curr_doc.second == curr_prior) {
      if (curr_doc.first == target) {
        cout << result << '\n';
        return;
      }

      result++;
      temp = 0;
      break_index--;
    } else {
      docs.push(curr_doc);
      temp++;
    }

    if (temp == break_index) {
      temp = 0;
      curr_prior--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    solve();
  }
}
