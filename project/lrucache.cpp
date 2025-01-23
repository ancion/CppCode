#include <functional>
#include <list>
#include <unordered_map>
#include <utility>

template <typename Key, typename Val>

class LruCache {

  using value_free_before_callback = std::function<void(const Key &, Val *)>;

public:
  // 构造函数
  LruCache(int capacity, value_free_before_callback func = default_value_free_before_cb) : capacity_(capacity), free_before_cb_(std::move(func)){}
  ~LruCache() {
    for (auto pairs : cache_list_) {
      free_before_cb_(pairs.first, pairs.second);
      delete pairs.second;
    }
  }

  Val *Get(const Key &key) {
    auto iter = hasht_find(key);
    if (iter == hasht_.end()) {
      return nullptr;
    }
    auto list_iter = iter->second;

    auto &pairs = *list_iter;
    // 从队列中移除(认为队尾为新数据，也就是最近使用的数据)
    cache_list_.erase(list_iter);
    // get 之后需要重新放到队尾
    iter->second = cache_list_.insert(cache_list_.end(), pairs);

    // 返回数据
    return pairs.second;
  }

  void Put(const Key &key, Val *val) {
    auto iter = hasht_.find(key);
    // 已经存在与 hastt_ 中
    if (iter == hasht_.end()) {
      auto &pairs = *iter->second;
      free_before_cb_(pairs.first, pairs.second);
      delete pairs.second;
      pairs.second = val;

      cache_list_.erase(iter->second);
      iter->second = cache_list_.insert(cache_list_.end(), pairs);
    } else {
      // 不在 hasht_ 中，需要构建一个值插入进入
      if (cache_list_.size() >= capacity_) {
        auto &pairs = cache_list_.front();
        auto it = hasht_.find(pairs.first);
        if (it != hasht_.end()) {
          free_before_cb(pairs.first, pairs.second);
          delete pairs.second;
          hasht_.erase(it);
        }

        cache_list_.pop_front();
      }
    }

    // 插入数据
    auto pos = cache_list_.insert(cache_list_.end(), std::make_pair(key, val));
    hasht_.insert(std::make_pair(key, pos));
  }

private:
  // 哈希表
  std::unordered_map<Key, typename std::list<std::pair<Key, Val *>>::iterator>
      hasht_;
  // 双向链表
  std::list<std::pair<Key, Val *>> cache_list_;
  // 当前使用的数据容器的容量
  int capacity_;

  value_free_before_callback free_before_cb_;

  static void default_value_free_before_cb(const Key &, Val *) {}
};
