#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(const pair<int, int>& first, const pair<int, int>& second) {
  if (first.second == second.second)
    return first.first < second.first;
  return first.second < second.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  vector<pair<int, int> > vec;

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;

    vec.push_back(pair<int, int>(start, end));
  }

  sort(vec.begin(), vec.end(), cmp);

  pair<int, int> last(0, 0);
  int cnt = 0;

  for (vector<pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++) {
    if (it->first >= last.second) {
      cnt++;
      last = *it;
    }
  }

  cout << cnt << '\n';
}
