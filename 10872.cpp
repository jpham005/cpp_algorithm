#include <iostream>

using namespace std;

int n;
int result[13];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  result[0] = 1;
  result[1] = 1;
  result[2] = 2;
  result[3] = 6;
  result[4] = 24;
  result[5] = 120;
  result[6] = 720;
  result[7] = 5040;
  result[8] = 40320;
  result[9] = 362880;
  result[10] = 3628800;
  result[11] = 39916800;
  result[12] = 479001600;

  cout << result[n] << '\n';
}
