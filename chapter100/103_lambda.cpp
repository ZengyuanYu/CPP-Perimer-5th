// 103_lambda.cpp — Lambda 表达式
// 编译：g++ -std=c++14 -o 103_lambda 103_lambda.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

// ==================== main ====================

int main() {
    // 1. 基本 lambda
    cout << "===== 1. 基本 lambda =====" << endl;
    auto greet = []() { cout << "  Hello, Lambda!" << endl; };
    greet();

    auto add = [](int a, int b) { return a + b; };
    cout << "  add(3, 4) = " << add(3, 4) << endl;

    // 指定返回类型
    auto divide = [](double a, double b) -> int { return static_cast<int>(a / b); };
    cout << "  divide(7.0, 2.0) = " << divide(7.0, 2.0) << endl;

    // 2. 捕获列表
    cout << "\n===== 2. 捕获列表 =====" << endl;

    int x = 10, y = 20;

    // 值捕获（拷贝）
    auto byValue = [x, y]() { cout << "  值捕获: x=" << x << " y=" << y << endl; };
    x = 999;  // 不影响 lambda 内的 x
    byValue();

    // 引用捕获
    int counter = 0;
    auto byRef = [&counter]() { ++counter; };
    byRef(); byRef(); byRef();
    cout << "  引用捕获 counter = " << counter << endl;

    // [=] 全部值捕获, [&] 全部引用捕获
    int a = 1, b = 2, c = 3;
    auto allByVal = [=]() { return a + b + c; };
    cout << "  [=] a+b+c = " << allByVal() << endl;

    auto allByRef = [&]() { a = 10; b = 20; c = 30; };
    allByRef();
    cout << "  [&] 修改后: a=" << a << " b=" << b << " c=" << c << endl;

    // 混合捕获：全部值捕获 + 某个引用捕获
    int total = 0;
    int nums[] = {1, 2, 3, 4, 5};
    auto mixed = [&total]() { /* 仅 total 引用捕获 */ };
    for_each(begin(nums), end(nums), [&total](int n) { total += n; });
    cout << "  [&total] 求和 = " << total << endl;

    // 3. mutable lambda（值捕获的变量可修改）
    cout << "\n===== 3. mutable lambda =====" << endl;
    int id = 0;
    auto nextId = [id]() mutable { return id++; };  // id 是拷贝，可修改
    cout << "  " << nextId() << " " << nextId() << " " << nextId() << endl;
    cout << "  原始 id = " << id << "（未被修改）" << endl;

    // 4. Lambda 作为 STL 算法参数
    cout << "\n===== 4. Lambda + STL 算法 =====" << endl;

    // sort 自定义比较
    vector<string> words = {"banana", "apple", "cherry", "date"};
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.size() < b.size();  // 按长度排序
    });
    cout << "  按长度排序: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    // count_if
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int evens = count_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    cout << "  偶数个数: " << evens << endl;

    // for_each
    cout << "  平方: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n * n << " "; });
    cout << endl;

    // transform
    vector<int> doubled(numbers.size());
    transform(numbers.begin(), numbers.end(), doubled.begin(), [](int n) { return n * 2; });
    cout << "  翻倍: ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    // accumulate + lambda
    int sum = accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int n) { return acc + n; });
    cout << "  求和: " << sum << endl;

    // 5. 泛型 lambda（C++14）
    cout << "\n===== 5. 泛型 lambda（C++14） =====" << endl;
    auto printPair = [](const auto& a, const auto& b) {
        cout << "  (" << a << ", " << b << ")" << endl;
    };
    printPair(42, "hello");
    printPair(3.14, 2.71);

    // 泛型 lambda 用于不同容器
    auto printContainer = [](const auto& container) {
        for (const auto& item : container) cout << item << " ";
        cout << endl;
    };
    cout << "  vector: "; printContainer(numbers);
    cout << "  string: "; printContainer(words);

    // 6. 存储 lambda（std::function）
    cout << "\n===== 6. std::function 存储 lambda =====" << endl;
    vector<function<int(int, int)>> ops;
    ops.push_back([](int a, int b) { return a + b; });
    ops.push_back([](int a, int b) { return a * b; });
    ops.push_back([](int a, int b) { return a - b; });
    string names[] = {"+", "*", "-"};
    for (size_t i = 0; i < ops.size(); ++i)
        cout << "  3 " << names[i] << " 4 = " << ops[i](3, 4) << endl;

    cout << "\nAll lambda examples passed!" << endl;
    return 0;
}
