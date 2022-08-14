#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;

    vec.push_back(input);
  }

  int target;
  cin >> target;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i] == target)
      cnt++;
  }

  cout << cnt << "\n";
}
