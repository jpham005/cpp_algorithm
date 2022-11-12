#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int> > coin;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;
    coin.push_back(pair<int, int>(curr, 0));
  }

  sort(coin.begin(), coin.end());

  for (vector<pair<int, int> >::size_type i = 0; i < coin.size(); i++) {
    coin[coin.size() - 1 - i].second = k / coin[coin.size() - 1 - i].first;
    k -= coin[coin.size() - 1 - i].first * coin[coin.size() - 1 - i].second;
  }

  int cnt = 0;
  for (vector<pair<int, int> >::size_type i = 0; i < coin.size(); i++) {
    cnt += coin[i].second;
  }

  cout << cnt << '\n';
}
