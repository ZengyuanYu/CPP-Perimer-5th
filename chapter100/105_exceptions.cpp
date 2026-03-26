// 105_exceptions.cpp — 异常处理（try/catch/throw、自定义异常、RAII）
// 编译：g++ -std=c++14 -o 105_exceptions 105_exceptions.cpp

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>
#include <fstream>
using namespace std;

// ==================== 1. 自定义异常类 ====================

class FileError : public runtime_error {
public:
    FileError(const string& filename, const string& msg)
        : runtime_error(msg), filename_(filename) {}

    const string& filename() const { return filename_; }

private:
    string filename_;
};

class NetworkError : public runtime_error {
public:
    NetworkError(const string& host, int code)
        : runtime_error("Network error: " + host + " (code " + to_string(code) + ")"),
          host_(host), code_(code) {}

    const string& host() const { return host_; }
    int code() const { return code_; }

private:
    string host_;
    int code_;
};

// ==================== 2. RAII 资源管理类 ====================

// 用 RAII 管理动态分配的资源
class DatabaseConnection {
public:
    DatabaseConnection(const string& connStr) : connStr_(connStr) {
        cout << "  [DB] 连接: " << connStr_ << endl;
    }

    ~DatabaseConnection() {
        cout << "  [DB] 断开: " << connStr_ << endl;
    }

    void query(const string& sql) {
        cout << "  [DB] 执行: " << sql << endl;
        if (sql.find("DROP") != string::npos) {
            throw runtime_error("Dangerous SQL: " + sql);
        }
    }

private:
    string connStr_;
};

// ==================== 3. 函数模板：捕获多种异常 ====================

void riskyOperation(int mode) {
    switch (mode) {
        case 0:
            throw runtime_error("runtime error occurred");
        case 1:
            throw FileError("config.txt", "file not found");
        case 2:
            throw NetworkError("api.example.com", 503);
        case 3:
            throw 42;  // 抛出非标准异常类型
        case 4:
            throw;     // rethrow（需在 catch 块中使用才有意义）
        default:
            cout << "  正常执行" << endl;
    }
}

// ==================== 4. noexcept 示例 ====================

int addNoThrow(int a, int b) noexcept {
    return a + b;
}

// ==================== main ====================

int main() {
    // 1. 基本 try/catch/throw
    cout << "===== 1. 基本异常处理 =====" << endl;
    try {
        cout << "  抛出异常前" << endl;
        throw runtime_error("something went wrong");
        cout << "  这行不会执行" << endl;
    } catch (const runtime_error& e) {
        cout << "  捕获: " << e.what() << endl;
    }

    // 2. 多种异常类型
    cout << "\n===== 2. 捕获多种异常类型 =====" << endl;
    for (int mode = 0; mode <= 3; ++mode) {
        try {
            riskyOperation(mode);
        } catch (const FileError& e) {
            cout << "  FileError: " << e.what() << ", file=" << e.filename() << endl;
        } catch (const NetworkError& e) {
            cout << "  NetworkError: " << e.what() << ", code=" << e.code() << endl;
        } catch (const runtime_error& e) {
            cout << "  RuntimeError: " << e.what() << endl;
        } catch (...) {
            cout << "  捕获未知异常" << endl;
        }
    }

    // 3. 异常继承层次：基类 catch 放最后
    cout << "\n===== 3. catch 顺序与继承 =====" << endl;
    try {
        throw NetworkError("localhost", 404);
    } catch (const NetworkError& e) {
        // 派生类在前，优先匹配
        cout << "  精确捕获 NetworkError" << endl;
    } catch (const runtime_error& e) {
        // 基类兜底
        cout << "  兜底捕获 runtime_error" << endl;
    }

    // 4. rethrow
    cout << "\n===== 4. 重新抛出（rethrow） =====" << endl;
    try {
        try {
            throw runtime_error("inner error");
        } catch (const runtime_error& e) {
            cout << "  内层捕获: " << e.what() << endl;
            throw;  // rethrow 原始异常
        }
    } catch (const runtime_error& e) {
        cout << "  外层捕获 rethrow: " << e.what() << endl;
    }

    // 5. RAII：异常安全的资源管理
    cout << "\n===== 5. RAII 异常安全 =====" << endl;
    try {
        DatabaseConnection db("server=localhost;db=test");
        db.query("SELECT * FROM users");
        db.query("DROP TABLE users");  // 抛出异常
        cout << "  这行不会执行" << endl;
    } catch (const runtime_error& e) {
        cout << "  捕获: " << e.what() << endl;
        // RAII 保证 db 的析构函数被调用，连接自动断开
    }

    // 6. unique_ptr 的异常安全
    cout << "\n===== 6. unique_ptr 异常安全 =====" << endl;
    try {
        auto resource = make_unique<int[]>(100);
        cout << "  资源已分配" << endl;
        throw runtime_error("oops");
        // resource 会自动释放，不会内存泄漏
    } catch (const runtime_error& e) {
        cout << "  捕获: " << e.what() << endl;
        cout << "  unique_ptr 已自动释放资源" << endl;
    }

    // 7. 标准异常类
    cout << "\n===== 7. 常见标准异常 =====" << endl;
    try {
        vector<int> v;
        v.at(10);  // 抛出 out_of_range
    } catch (const out_of_range& e) {
        cout << "  out_of_range: " << e.what() << endl;
    }

    // 8. noexcept 说明符
    cout << "\n===== 8. noexcept =====" << endl;
    cout << "  addNoThrow noexcept? " << noexcept(addNoThrow(1, 2)) << endl;
    cout << "  addNoThrow(3, 4) = " << addNoThrow(3, 4) << endl;

    // 9. 函数 try 块（构造函数中的异常处理）
    cout << "\n===== 9. 构造函数 try 块 =====" << endl;
    try {
        // 模拟构造函数中捕获异常
        int* arr = new int[10];
        try {
            throw bad_alloc();
        } catch (...) {
            delete[] arr;
            cout << "  构造失败，资源已清理" << endl;
            throw;
        }
    } catch (...) {
        cout << "  异常已传播到调用者" << endl;
    }

    cout << "\nAll exception examples passed!" << endl;
    return 0;
}
