#include <iostream>
#include <vector>
#include <algorithm>

int sum() {
    std::vector<int> nums = {3, 1, 4, 1, 5, 6, 8};
    int sum = 0;

    // 使用 lambda 计算所有偶数的和
    std::for_each(nums.begin(), nums.end(), [&sum](int n) {
        if (n % 2 == 0) sum += n;
    });

    std::cout << "Sum of even numbers: " << sum << std::endl; // 输出：Sum of even numbers: 18
    return 0;
}

int main() {
    std::vector<int> nums = {3, 1, 4, 1, 5};
    // 使用 lambda 排序（降序）
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    for (auto n : nums) {
        std::cout << n << " ";  // 输出：5 4 3 1 1
    }
    std::cout << std::endl;

    sum();

    return 0;
}