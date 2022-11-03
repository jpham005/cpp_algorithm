#include <iostream>

using namespace std;

int n;

int heap[100000];
int size = 0;

void insert_heap(int x) {
  heap[size++] = x;
  int here = size;

  while (here > 1 && heap[here / 2 - 1] > heap[here - 1]) {
      swap(heap[here / 2 - 1], heap[here - 1]);
      here /= 2;
  }
}

void delete_heap() {
  swap(heap[0], heap[--size]);

  for (int curr = 1; curr * 2 <= size; ) {
    if (heap[curr - 1] > heap[curr * 2 - 1]) {
      if (curr * 2 + 1 <= size && heap[curr * 2 - 1] > heap[curr * 2]) {
        swap(heap[curr - 1], heap[curr * 2]);
        curr = curr * 2 + 1;
        continue;
      }

      swap(heap[curr - 1], heap[curr * 2 - 1]);
      curr *= 2;
      continue;
    }

    if (curr * 2 + 1 <= size && heap[curr - 1] > heap[curr * 2]) {
      swap(heap[curr - 1], heap[curr * 2]);
      curr = curr * 2 + 1;
      continue;
    }

    break;
  }
}

void printall() {
  for (int i = 0; i < size; i++) {
    cout << heap[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int curr;
    cin >> curr;

    if (curr == 0) {
      if (size == 0) {
        cout << "0\n";
        continue;
      }

      cout << heap[0] << '\n';
      delete_heap();
//      printall();
      continue;
    }

    insert_heap(curr);
//    printall();
  }
}
