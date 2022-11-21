#include <iostream>

using namespace std;

long long memo[100001];
int n,m,i,j;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);


  cin >> n >> m;

  for (int k = 1; k <= n; k++) {
    int temp;
    cin >> temp;
    memo[k] = memo[k - 1] + temp;
  }

  for (int k = 0; k < m; k++) {
    cin >> i >> j;
    cout << memo[j] - memo[i - 1] << '\n';
  }
}
