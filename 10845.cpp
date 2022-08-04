#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
public:
  Node() : _t(), _next(nullptr) {}
  Node(const T& t) : _t(t), _next(nullptr) {}
  ~Node() {}

  T _t;
  Node* _next;
};

template <typename T, typename allocator = std::allocator<Node<T> > >
class Queue {
private:
  Node<T>* _front;
  Node<T>* _end;
  std::size_t _size;
  allocator _alloc;

public:
  Queue() : _front(nullptr), _end(nullptr), _size(0), _alloc() {}
  ~Queue() { clear(); }

  void push(T t) {
    if (!_size) {
      _front = _alloc.allocate(1);
      _alloc.construct(_front, t);
      _end = _front;
    } else {
      _end->_next = _alloc.allocate(1);
      _alloc.construct(_end->_next, t);
      _end = _end->_next;
    }

    _size++;
  }

  T pop() {
    Node<T>* temp = _front->_next;

    T ret(_front->_t);

    _alloc.destroy(_front);
    _alloc.deallocate(_front, 1);

    _front = temp;

    _size--;

    return ret;
  }

  std::size_t size() const throw() { return _size; }

  bool empty() const throw() { return _size == 0; }

  const T& front() const throw() { return _front->_t; }

  const T& back() const throw() { return _end->_t; }

  void clear() {
    for (Node<T>* temp; _front; _front = temp) {
      temp = _front->_next;
      _alloc.destroy(_front);
      _alloc.deallocate(_front, 1);
    }
    _size = 0;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  Queue<int> q;

  for (int i = 0; i < n; i++) {
    std::string str;
    int input;

    cin >> str;

    if (str == "push") {
      cin >> input;
      q.push(input);
    } else if (str == "size") {
      cout << q.size() << "\n";
    } else if (str == "pop") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.pop() << "\n";
      }
    } else if (str == "empty") {
      cout << static_cast<int>(q.empty()) << "\n";
    } else if (str == "front") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.front() << "\n";
      }
    } else {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.back() << "\n";
      }
    }
  }

  return 0;
}
