#include <iostream>
#include <limits>

using namespace std;

int heap[100000];
int size;

void insertHeap(const int& x) {
  heap[size++] = x;

  int curr = size;
  while (curr > 1) {
    if (heap[curr - 1] > heap[curr / 2 - 1]) {
      swap(heap[curr - 1], heap[curr / 2 - 1]);
      curr /= 2;
      continue;
    }

    break;
  }
}

void deleteHeap() {
  swap(heap[0], heap[size - 1]);
  --size;

  int curr = 1;
  while (curr * 2 <= size) {
    int left, right;
    left = heap[curr * 2 - 1];
    right = curr * 2 + 1 <= size ? heap[curr * 2] : numeric_limits<int>::min();

    if (heap[curr - 1] < left && left > right) {
      swap(heap[curr - 1], heap[curr * 2 -1]);
      curr *= 2;
      continue;
    }

    if (heap[curr - 1] < right) {
      swap(heap[curr - 1], heap[curr * 2]);
      curr += curr + 1;
      continue;
    }

    break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;

    if (!x) {
      if (!size) {
        cout << "0\n";
        continue;
      }

      cout << heap[0] << '\n';
      deleteHeap();
      continue;
    }

    insertHeap(x);
  }
}
