// 102_move_semantics.cpp — 移动语义（右值引用、std::move、移动构造/赋值）
// 编译：g++ -std=c++14 -o 102_move_semantics 102_move_semantics.cpp

#include <iostream>
#include <string>
#include <vector>
#include <utility>  // std::move
using namespace std;

// ==================== 演示类：BigBuffer ====================

class BigBuffer {
public:
    // 构造函数
    explicit BigBuffer(size_t size) : size_(size), data_(new int[size]) {
        cout << "  [构造] BigBuffer(" << size_ << ")" << endl;
        for (size_t i = 0; i < size_; ++i) data_[i] = static_cast<int>(i);
    }

    // 拷贝构造（深拷贝，昂贵）
    BigBuffer(const BigBuffer& other) : size_(other.size_), data_(new int[other.size_]) {
        cout << "  [拷贝构造] 复制 " << size_ << " 个元素（深拷贝）" << endl;
        for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
    }

    // 拷贝赋值
    BigBuffer& operator=(const BigBuffer& other) {
        cout << "  [拷贝赋值] 复制 " << other.size_ << " 个元素" << endl;
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
        return *this;
    }

    // 移动构造（窃取资源，廉价）
    BigBuffer(BigBuffer&& other) noexcept : size_(other.size_), data_(other.data_) {
        cout << "  [移动构造] 窃取 " << size_ << " 个元素（浅拷贝）" << endl;
        other.data_ = nullptr;
        other.size_ = 0;
    }

    // 移动赋值
    BigBuffer& operator=(BigBuffer&& other) noexcept {
        cout << "  [移动赋值] 窃取 " << other.size_ << " 个元素" << endl;
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    // 析构
    ~BigBuffer() {
        cout << "  [析构] BigBuffer(" << size_ << ")" << endl;
        delete[] data_;
    }

    size_t size() const { return size_; }
    int get(size_t i) const { return data_[i]; }

private:
    size_t size_;
    int* data_;
};

// ==================== 工厂函数（返回临时对象，触发移动语义） ====================

BigBuffer createBuffer(size_t size) {
    BigBuffer buf(size);
    return buf;  // NRVO 或移动构造，不会拷贝
}

// ==================== 左值引用 vs 右值引用 ====================

void process(const BigBuffer& buf) {
    cout << "  左值引用重载：处理 buf，size = " << buf.size() << endl;
}

void process(BigBuffer&& buf) {
    cout << "  右值引用重载：移动 buf，size = " << buf.size() << endl;
}

// ==================== main ====================

int main() {
    // 1. 拷贝 vs 移动的对比
    cout << "===== 1. 拷贝构造 vs 移动构造 =====" << endl;
    BigBuffer a(1000);
    cout << "  拷贝 a:" << endl;
    BigBuffer b(a);                         // 拷贝构造
    cout << "  移动 a:" << endl;
    BigBuffer c(move(a));                   // 移动构造
    cout << "  a.size() = " << a.size() << "（已被移动，变为空）" << endl;

    // 2. 工厂函数返回值优化 / 移动
    cout << "\n===== 2. 工厂函数（返回值） =====" << endl;
    BigBuffer d = createBuffer(500);
    cout << "  d.size() = " << d.size() << endl;

    // 3. std::move 用于容器
    cout << "\n===== 3. std::move + vector =====" << endl;
    vector<BigBuffer> vec;
    cout << "  push_back 左值（触发拷贝）:" << endl;
    BigBuffer e(100);
    vec.push_back(e);                       // 拷贝
    cout << "  push_back 右值（触发移动）:" << endl;
    vec.push_back(BigBuffer(200));          // 移动（临时对象）
    cout << "  push_back move（触发移动）:" << endl;
    vec.push_back(move(e));                // 移动
    cout << "  e.size() = " << e.size() << "（已被移动）" << endl;

    // 4. 函数重载分发
    cout << "\n===== 4. 左值/右值引用重载分发 =====" << endl;
    BigBuffer f(50);
    process(f);                             // 调用左值引用版本
    process(BigBuffer(50));                // 调用右值引用版本
    process(move(f));                       // 调用右值引用版本

    cout << "\nAll move semantics examples passed!" << endl;
    return 0;
}
