
// delete 可用来表示删除 (可以用于方法和构造函数,则该方法或构造函数不可用)
// default 可表示使用默认值，
//


// 使用 default 和 delete 来构建一个与 std::unique_ptr 一样行为的类
// 不允许使用拷贝和赋值的, 允许使用移动(std::move)的
struct PtrUnique {

  void *dataPtr;

  // 不允许使用默认构造函数
  PtrUnique() = delete;

  // 不允许使用拷贝构造函数
  PtrUnique(const PtrUnique  &) = delete;

  // 不允许使用赋值运算符
  PtrUnique & operator=(const PtrUnique &) = delete;

  // 允许使用移动构建函数
  PtrUnique(PtrUnique &&) = default;

  // 允许使用移动赋值运算符
  PtrUnique & operator=(PtrUnique &&) = default;
};
