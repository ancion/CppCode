#include <functional>
#include <list>
#include <unordered_map>
#include <utility>

template <typename Key, typename Val>
struct Node{
  Key key; 
  Val *val;
  Node *prev;
  Node *next;
  Node(const Key &key, Val *val) : key(key), val(val), prev(nullptr), next(nullptr){}
};


template <typename Key, typename Val>
class Queue{ 

  using node_t = Node<Key, Val>;

public:
  Queue() { base_.next = &base_; base_.prev = &base_; }
  ~Queue() {
    while(!empty()) {
      node_t *node = head();
      remove(node);
      delete node;
    }
  }

  void insert_tail(node_t *node) {
    node -> prev = base_.prev;
    node -> next = &base_;
    base_.next->prev = node;
    base_.prev = node;
  }

  void insert_head(node_t *node) {
    node -> prev = &base_;
    node -> next = base_.next;
    base_.next->prev = node;
    base_.next = node;
  }

  node_t *head() {
    return base_.next;
  }

  node_t *tail() {
    return base_.prev;
  }

  void remove(node_t *node) {
    node -> prev -> next = node -> next;
    node -> next -> prev = node -> prev;
  }

  bool empty() {
    return base_.next == &base_;
  }

private:
  node_t base_;
};


template <typename Key, typename Val>
class LruCache {
  using value_free_before_callback = std::function<void(const Key &, Val *)>;
  using node_t = Node<Key, Val>;

public:
  // 构造函数
  LruCache(int capacity, value_free_before_callback func = default_value_free_before_cb) : capacity_(capacity), free_before_cb_(std::move(func)){}
  ~LruCache() {
    for (auto iter : hasht_) {
      auto node = iter.second;
      free_before_cb(node -> key, node -> val);
      delete node -> val;
    }
  }

  Val *Get(const Key &key) {
    auto iter = hasht_.find(key);
    if (iter == hasht_.end()) {
      return nullptr;
    }
    auto node = iter -> second;
    cache_list_.remove(node);
    cache_list_.insert_head(node);
    return node -> val;
  }

  void Put(const Key &key, Val *val) {
    auto iter = hasht_.find(key);
    if (iter == hasht_.end()) {
      if (cache_list_.size() >= capacity_) {
        auto node = cache_list_.tail();
        hasht_.erase(node -> key);
        cache_list_.remove(node);
        free_before_cb_(node -> key, node -> val);
        delete node -> val;
        delete node;
      }
      auto node = new node_t(key, val);
      cache_list_.insert_head(node);
      hasht_.insert(std::make_pair(key, node));
    } else {
      auto node = iter -> second;
      node -> val = val;
      cache_list_.remove(node);
      cache_list_.insert_head(node);
    }
  }

private:
  // 哈希表
  std::unordered_map<Key, node_t*> hasht_;

  // 双向链表
  Queue<Key, Val> cache_list_;
  // 当前使用的数据容器的容量
  int capacity_;

  value_free_before_callback free_before_cb_;

  static void default_value_free_before_cb(const Key &, Val *) {}
};
