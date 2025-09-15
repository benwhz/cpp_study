#include <iostream>
#include <string>
#include <vector>

int main() {
    auto i = 42;          // i 被推导为 int
    auto s = "hello";     // s 被推导为 const char*
    auto vec = std::vector<int>{1, 2, 3};  // vec 被推导为 std::vector<int>

    std::cout << i << " " << s << std::endl;
    return 0;
}