#include <iostream>
#include <map>
#include <set>

#include <cmath>

using namespace std;

typedef map<int, int> map_type;
typedef map_type::iterator it;
typedef pair<it, bool> m_pair;

int main() {
  int n;

  cin >> n;

  map<int, int> map;

  for (int i = 0, input; i < n; i++) {
    cin >> input;

    m_pair pair = map.insert(map_type::value_type(input, 1));

    if (!pair.second)
      (pair.first->second)++;
  }

  int sum = 0;
  int median, median_counter = 0;
  bool flag = true;
  pair<int, int> mode = {0xffffffff, 0xffffffff};

  set<int> mode_recoder;

  for (it it_ = map.begin(); it_ != map.end(); it_++) {
    sum += it_->first * it_->second;

    median_counter += it_->second;
    if (median_counter >= (n + 1) / 2 && flag) {
      median = it_->first;
      flag = false;
    }

    if (it_->second > mode.second) {
      mode.first = it_->first;
      mode.second = it_->second;
    }
  }

  for (it it_ = map.begin(); it_ != map.end(); it_++) {
    if (it_->second == mode.second)
      mode_recoder.insert(it_->first);
  }

  mode.first = mode_recoder.size() == 1 ? *(mode_recoder.begin()) : *(++mode_recoder.begin());

  cout << lround((float)sum / (float)n) << endl;
  cout << median << endl;
  cout << mode.first << endl;
  cout << (--map.end())->first - map.begin()->first << endl;
}
