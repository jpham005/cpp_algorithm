#include <iostream>

using namespace std;
int arr[31];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


  for (int i = 1; i <= 28; i++) {
    int n;
    cin >> n;
    arr[n] = 1;
  }

  for (int i = 1; i  <= 30; i++) {
    if (arr[i] == 0) {
      cout << i << '\n';
    }
  }
}
