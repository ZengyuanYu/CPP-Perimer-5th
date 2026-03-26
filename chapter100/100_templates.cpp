// 100_templates.cpp — 模板（函数模板、类模板、特化）
// 编译：g++ -std=c++14 -o 100_templates 100_templates.cpp

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
using namespace std;

// ==================== 函数模板 ====================

// 1. 基本函数模板
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

// 2. 多类型参数模板
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

// 3. 函数模板特化 —— 针对 const char* 的特殊处理
template <>
const char* myMax<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// ==================== 类模板 ====================

// 4. 简易栈类模板
template <typename T, int Capacity = 10>
class Stack {
public:
    Stack() : top_(-1) {}

    void push(const T& val) {
        if (top_ < Capacity - 1)
            data_[++top_] = val;
    }

    T pop() {
        return data_[top_--];
    }

    bool empty() const { return top_ == -1; }
    int size() const { return top_ + 1; }

private:
    T data_[Capacity];
    int top_;
};

// 5. 类模板特化 —— 针对 bool 的位压缩栈
template <int Capacity>
class Stack<bool, Capacity> {
public:
    Stack() : size_(0) {}

    void push(bool val) {
        if (size_ < Capacity) {
            int idx = size_ / 8;
            int bit = size_ % 8;
            if (val) data_[idx] |= (1 << bit);
            else     data_[idx] &= ~(1 << bit);
            ++size_;
        }
    }

    bool pop() {
        --size_;
        int idx = size_ / 8;
        int bit = size_ % 8;
        return (data_[idx] >> bit) & 1;
    }

    int size() const { return size_; }

private:
    unsigned char data_[(Capacity + 7) / 8] = {};
    int size_;
};

// ==================== 编译期类型检查 ====================

// 6. static_assert + type_traits
template <typename T>
T safeDivide(T a, T b) {
    // 仅允许算术类型调用此模板
    static_assert(is_arithmetic<T>::value, "T must be an arithmetic type");
    return a / b;
}

// ==================== main ====================

int main() {
    cout << "===== 函数模板 =====" << endl;
    cout << "myMax(3, 7)       = " << myMax(3, 7) << endl;           // int
    cout << "myMax(3.14, 2.72) = " << myMax(3.14, 2.72) << endl;     // double
    cout << "myMax(\"apple\", \"banana\") = " << myMax("apple", "banana") << endl;

    cout << "\n===== 多类型参数模板 =====" << endl;
    cout << "add(1, 2.5) = " << add(1, 2.5) << endl;  // int + double → double

    cout << "\n===== 类模板：int 栈 =====" << endl;
    Stack<int, 5> intStack;
    for (int i = 1; i <= 5; ++i) intStack.push(i * 10);
    cout << "size = " << intStack.size() << ", pop: ";
    while (!intStack.empty()) cout << intStack.pop() << " ";
    cout << endl;

    cout << "\n===== 类模板：string 栈（默认容量） =====" << endl;
    Stack<string> strStack;
    strStack.push("hello");
    strStack.push("world");
    cout << "pop: " << strStack.pop() << " " << strStack.pop() << endl;

    cout << "\n===== 类模板特化：bool 栈 =====" << endl;
    Stack<bool, 10> boolStack;
    boolStack.push(true);
    boolStack.push(false);
    boolStack.push(true);
    cout << "pop: " << boolStack.pop() << " " << boolStack.pop() << " " << boolStack.pop() << endl;

    cout << "\n===== static_assert 类型检查 =====" << endl;
    cout << "safeDivide(10, 3) = " << safeDivide(10, 3) << endl;
    // safeDivide("a", "b");  // 编译错误：const char* 不是算术类型

    cout << "\nAll template examples passed!" << endl;
    return 0;
}
