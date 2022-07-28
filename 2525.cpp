#include <iostream>

using namespace std;

const static int kMIN_PER_HOUR = 60;
const static int kHOUR_PER_DAY = 24;

int main() {
  int min, hour, req_min;
  int flow;

  cin >> hour >> min >> req_min;

  min += req_min;
  flow = min / kMIN_PER_HOUR;
  min %= kMIN_PER_HOUR;
  hour = (hour + flow) % kHOUR_PER_DAY;

  cout << hour << " " << min << endl;
}
