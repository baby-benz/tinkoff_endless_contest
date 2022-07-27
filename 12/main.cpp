#include <iostream>

class Solution {
public:
    static unsigned long long countCombinations(long long n, unsigned int nums[3], unsigned int curNumId) {
        unsigned long long combinationsCount = 0;

        if (n < 1) {
            return combinationsCount;
        }

        combinationsCount++;

        for (unsigned int i = curNumId; i < 3; i++, curNumId++) {
            combinationsCount += countCombinations(n - nums[curNumId], nums, curNumId);
        }

        return combinationsCount;
    }
};

int main() {
    long long n;
    unsigned int nums[3];

    std::cin >> n >> nums[0] >> nums[1] >> nums[2];

    std::cout << Solution::countCombinations(n, nums, 0) << std::endl;

    return 0;
}
