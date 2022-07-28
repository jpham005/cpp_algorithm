#include <iostream>
#include <set>

using namespace std;

typedef set<int>::iterator it;
typedef pair<it, bool> num_pair;

int main() {
  set<int> eye;
  int result = 0;
  it duplicated;

  for (int i = 0, input; i < 3; i++) {
    cin >> input;

    num_pair pair = eye.insert(input);

    if (!pair.second)
      duplicated = pair.first;
  }

  switch (eye.size()) {
    case 1:
      cout << 10000 + *eye.begin() * 1000 << endl;
      break;
    case 2:
      cout << 1000 + *duplicated * 100 << endl;
      break;
    case 3:
      cout << *(--eye.end()) * 100 << endl;
      break;
    default:
      throw std::runtime_error("oops!");
  }

  return (0);
}
