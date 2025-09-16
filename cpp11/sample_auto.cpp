#include <iostream>
#include <string>
#include <vector>

double get_product(double a, int b) {
    return a * b;
}

// Demonstrating 'auto' and 'decltype'
// C++11 introduced the 'auto' keyword for type inference and 'decltype' for deducing the type of an expression.
// it happens at compile time not runtime.
// 'auto' lets the compiler automatically deduce the type of a variable from its initializer.

int main() {
    auto i = 42;          // i 被推导为 int
    auto s = "hello";     // s 被推导为 const char*
    auto vec = std::vector<int>{1, 2, 3};  // vec 被推导为 std::vector<int>

    decltype(i) j = i;  // j 的类型与 i 相同，即 int
    decltype((i)) k = i; // k 的类型为 int&，因为 i 是一个变量
    k = 100;            // 修改 k 也会修改 i
    // Now i is 100
    std::cout << i << " " << s << std::endl;

    auto result = get_product(3.5, 2); // result 被推导为 double
    decltype(get_product(1.0, 1)) result2 = get_product(1.50, 10); // result2 的类型为 double

    std::cout << "result: " << result << std::endl; // Output: 7
    std::cout << "result2: " << result2 << std::endl; // Output: 15
    return 0;
}