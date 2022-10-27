#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
  long long len;
  cin >> len;

  long long r = 1;
  long long m = 1234567891;

  long long hash = 0;

  string str;

  cin >> str;

  for (long long i = 0; i < len; i++) {
    const long long curr = ((str[i] - 'a' + 1) * r) % m;
    hash += curr;
    r = (r * 31) % m;
  }

  cout << hash % m << '\n';
}
