#include <iostream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int arr[500000];
int n;

int lower_bound(int start, int end, int input) {
  if (start + 1 >= end) {
    if (arr[start] == input) {
      return start;
    }

    if (arr[end] == input) {
      return end;
    }

    return numeric_limits<int>::max();
  }

  if (arr[(start + end) / 2] < input) {
    return lower_bound((start + end) / 2, end, input);
  } else if (arr[(start + end) / 2] > input) {
    return lower_bound(start, (start + end) / 2, input);
  } else {
    return lower_bound(start, (start + end) / 2, input);
  }
}

int upper_bound(int start, int end, int input) {
  if (start + 1 >= end) {
    if (arr[end] == input)
      return end;

    if (arr[start] == input)
      return start;

    return numeric_limits<int>::max();
  }

  if (arr[(start + end) / 2] < input) {
    return upper_bound((start + end) / 2, end, input);
  } else if (arr[(start + end) / 2] > input) {
    return upper_bound(start, (start + end) / 2, input);
  } else {
    return upper_bound((start + end) / 2, end, input);
  }
}

int search(int input) {
  int upper = upper_bound(0, n - 1, input);
  int lower = lower_bound(0, n - 1, input);

  if (upper == numeric_limits<int>::max())
    return 0;

  return upper_bound(0, n - 1, input) - lower_bound(0, n - 1, input) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  cin >> m;

  int input;
  for (int i = 0; i < m - 1; i++) {
    cin >> input;
    cout << search(input) << ' ';
  }

  cin >> input;
  cout << search(input) << '\n';
}
