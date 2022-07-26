#include <iostream>

class Solution {
public:
    static unsigned int calculateCuts(unsigned long n) {
        unsigned int iterations = 0;

        unsigned long multipleOfTwo = 1;

        while (multipleOfTwo < n) {
            multipleOfTwo *= 2;
            iterations++;
        }

        return iterations;
    }
};

int main() {
    unsigned long n;

    std::cin >> n;

    std::cout << Solution::calculateCuts(n) << std::endl;

    return 0;
}
