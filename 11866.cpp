#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
  T _value;
  struct Node* _next;

  Node(T value, struct Node* next = nullptr) : _value(value), _next(next) {}
};

template <typename T>
class CircleQueue {
public:
  typedef struct Node<T> node_type;
  typedef node_type* node_pointer;

private:
  std::allocator<Node<T> > _alloc;
  node_pointer _head;
  node_pointer _tail;
  node_pointer _curr;
  std::size_t _size;

public:
  CircleQueue() : _head(nullptr), _tail(nullptr), _curr(nullptr), _size(0) {}
  ~CircleQueue() {
    while (_size--) {
      node_pointer temp = _head;

      _head = _head->_next;
      _alloc.destroy(temp);
      _alloc.deallocate(temp, 1);
    }
  }

  void push(T t) {
    if (!_size) {
      _head = _alloc.allocate(1);
      _alloc.construct(_head, t);
      _tail = _head;
      _curr = _head;
      _size++;

      return;
    }

    _tail->_next = _alloc.allocate(1);
    _alloc.construct(_tail->_next, t, _head);
    _tail = _tail->_next;
    _size++;
  }

  T pop(int k = 1) {
    node_pointer* temp = &_curr;
    node_pointer target;

    for (int i = 1; i < k; i++)
      temp = &((*temp)->_next);

    target = *temp;
    T ret = target->_value;
    *temp = (*temp)->_next;
    _curr = *temp;

    _alloc.destroy(target);
    _alloc.deallocate(target, 1);

    _size--;

    return ret;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;

  cin >> n >> k;

  CircleQueue<int> q;

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  cout << '<';
  for (int i = 0; i < n - 1; i++) {
    cout << q.pop(k) << ", ";
  }
  cout << q.pop(k) << ">\n";
}
