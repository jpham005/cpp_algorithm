#include <iostream>
#include <climits>

using namespace std;

int min_heap[1000005];
int max_heap[1000005];
int size;
int t, k;

void insert(int n) {
  if (size == 0) {
    min_heap[1] = n;
    max_heap[1] = n;
    size++;
    return;
  }

  min_heap[++size] = n;
  max_heap[size] = n;

  int temp = size;
  while (temp > 1 && min_heap[temp / 2] > min_heap[temp]) {
    swap(min_heap[temp / 2], min_heap[temp]);
    temp /= 2;
  }

  temp = size;
  while (temp > 1 && max_heap[temp / 2] < max_heap[temp]) {
    swap(max_heap[temp / 2], max_heap[temp]);
    temp /= 2;
  }
}

void delete_max_heap(int b_size, int target) {
  int i;
  for (i = 1; max_heap[i] != target; i++);

  swap(max_heap[i], max_heap[b_size]);

  b_size--;

  int curr = i;
  while (curr < size) {
    if (curr * 2 > size)
      break;
    int child1 = max_heap[curr * 2];

    int child2;
    if (curr * 2 + 1 > size) {
      child2 = INT_MIN;
    } else {
      child2 = max_heap[curr * 2 + 1];
    }

    if (max_heap[curr] < child1) {
      if (child1 > child2) {
        if (curr * 2 <= size)
          swap(max_heap[curr], max_heap[curr * 2]);
      } else if (curr * 2 + 1 <= size) {
        swap(max_heap[curr], max_heap[curr * 2 + 1]);
      }
    } else if (max_heap[curr] < child2) {
      if (curr * 2 + 1 <= size)
        swap(max_heap[curr], max_heap[curr * 2 + 1]);
    } else {
      return;
    }
  }
}

void delete_min_heap(int b_size, int target) {
  int i;
  for (i = 1; min_heap[i] != target; i++);

  swap(min_heap[i], min_heap[b_size]);

  b_size--;

  int curr = i;
  while (curr < b_size) {
    if (curr * 2 > b_size)
      break;
    int child1 = min_heap[curr * 2];

    int child2;
    if (curr * 2 + 1 > b_size) {
      child2 = INT_MAX;
    } else {
      child2 = min_heap[curr * 2 + 1];
    }

    if (min_heap[curr] > child1) {
      if (child1 < child2) {
        if (curr * 2 <= b_size)
          swap(min_heap[curr], min_heap[curr * 2]);
      } else if (curr * 2 + 1 <= b_size) {
        if (curr * 2 + 1 <= b_size)
          swap(min_heap[curr], min_heap[curr * 2 + 1]);
      }
    } else if (min_heap[curr] > child2) {
      if (curr * 2 + 1 <= size)
        swap(min_heap[curr], min_heap[curr * 2 + 1]);
    } else {
      return;
    }
  }
}

void delete_heap(bool is_max) {
  if (size == 0) {
    return;
  }

  if (is_max) {
    delete_min_heap(size, max_heap[1]);
    swap(max_heap[1], max_heap[size]);

    size--;
    int curr = 1;
    while (curr < size) {
      if (curr * 2 > size)
        break;
      int child1 = max_heap[curr * 2];

      int child2;
      if (curr * 2 + 1 > size) {
        child2 = INT_MIN;
      } else {
        child2 = max_heap[curr * 2 + 1];
      }

      if (max_heap[curr] < child1) {
        if (child1 > child2) {
          if (curr * 2 <= size)
            swap(max_heap[curr], max_heap[curr * 2]);
        } else if (curr * 2 + 1 <= size) {
          swap(max_heap[curr], max_heap[curr * 2 + 1]);
        }
      } else if (max_heap[curr] < child2) {
        if (curr * 2 + 1 <= size)
          swap(max_heap[curr], max_heap[curr * 2 + 1]);
      } else {
        return;
      }
    }
  } else {
    delete_max_heap(size, min_heap[1]);
    swap(min_heap[1], min_heap[size]);


    size--;
    int curr = 1;
    while (curr < size) {
      if (curr * 2 > size)
        break;
      int child1 = min_heap[curr * 2];

      int child2;
      if (curr * 2 + 1 > size) {
        child2 = INT_MAX;
      } else {
        child2 = min_heap[curr * 2 + 1];
      }

      if (min_heap[curr] > child1) {
        if (child1 < child2) {
          if (curr * 2 <= size)
            swap(min_heap[curr], min_heap[curr * 2]);
        } else if (curr * 2 + 1 <= size) {
          swap(min_heap[curr], min_heap[curr * 2 + 1]);
        }
      } else if (min_heap[curr] > child2) {
        if (curr * 2 + 1 <= size)
          swap(min_heap[curr], min_heap[curr * 2 + 1]);
      } else {
        return;
      }
    }
  }
}

void solve() {
  cin >> k;

  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    int curr;
    cin >> curr;

    if (c == 'I') {
      insert(curr);
    } else if (c == 'D') {
      if (curr == 1) {
        delete_heap(true);
      } else {
        delete_heap(false);
      }
    }

//    for (int i = 0; i < size; i++) {
//      cout << max_heap[i] << ' ';
//    }
//    cout << '\n';
  }

  if (!size) {
    cout << "EMPTY\n";
  } else {
    cout << max_heap[1] << ' ' << min_heap[1] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}
