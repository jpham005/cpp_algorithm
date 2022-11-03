#include <iostream>

using namespace std;

int n;

int pos = 0, neg = 0, zero = 0;

void check_board(int* board, int start, int curr) {
  for (int i = 0; i < curr; i++) {
    for (int j = 0; j < curr; j++) {
      if (board[i * n + j + start] != board[start]) {
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            check_board(board, start + k * n * curr / 3 + curr / 3 * l, curr / 3);
          }
        }
        return;
      }
    }
  }

  if (board[start] > 0) pos++;
  if (board[start] == 0) zero++;
  if (board[start] < 0) neg++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int board[n * n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i * n + j];
    }
  }

  check_board(board, 0, n);

  cout << neg << '\n' << zero << '\n' << pos << '\n';
}
