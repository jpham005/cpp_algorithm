#include <iostream>
#include <list>
#include <unistd.h>
#include <cctype>
#include <climits>

using namespace std;

enum op {
  PLUS,
  MINUS
};

struct node {
  enum op oper;
  int n;

  node(enum op& oper, int& n): oper(oper), n(n) {}
};

list<struct node> li;
typedef list<struct node>::iterator iter;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char input[51];

  input[read(STDIN_FILENO, input, 50)] = 0;

  enum op curr_op = PLUS;
  for (int i = 0; input[i]; i++) {
    int n = 0;
    while (isdigit(input[i]) && input[i]) {
      n *= 10;
      n += input[i] - '0';
      i++;
    }

    li.push_back(list<struct node>::value_type(curr_op, n));

    if (input[i] == '+')
      curr_op = PLUS;
    else
      curr_op = MINUS;
  }

  int result = 0;
  for (iter it = li.begin(); it != li.end();) {
    if (it->oper == PLUS) {
      result += (it++)->n;
      continue;
    }

    result -= (it++)->n;
    while (it != li.end() && it->oper == PLUS) {
      result -= it->n;
      it++;
    }
  }

  cout << result << '\n';
}
