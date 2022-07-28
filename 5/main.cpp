#include <iostream>
#include <cmath>

class Solution {
public:
    static unsigned long long
    maxTests(const unsigned long long minTestBound, const unsigned long long maxTestBound) {
        unsigned long long maxTests = 0;

        unsigned int minTestBoundLen = log10l(minTestBound) + 1;
        unsigned int maxTestBoundLen = log10l(maxTestBound) + 1;

        if (minTestBoundLen == maxTestBoundLen) {
            maxTests += ord_digits(minTestBound, maxTestBound, minTestBoundLen);
        } else {
            maxTests += ord_digits_from_top(minTestBound, minTestBoundLen);

            maxTests += ord_digits_from_bottom(maxTestBound, maxTestBoundLen);

            for (unsigned int i = minTestBoundLen + 1; i < maxTestBoundLen; i++) {
                maxTests += 9;
            }
        }

        return maxTests;
    }

private:
    static unsigned int ord_digits(const unsigned long long minTestBound, const unsigned long long maxTestBound,
                                         const unsigned int testBoundLen) {
        const unsigned long long baseOrdNumber = ord_digit(testBoundLen);
        unsigned long long testNumber = baseOrdNumber;
        unsigned int testNumberMultiplier = 1;

        unsigned int ordDigits = 0;

        while (true) {
            if (testNumber >= minTestBound) {
                if (testNumber > maxTestBound) {
                    break;
                }
                ordDigits += 1;
            }
            testNumberMultiplier++;
            testNumber = baseOrdNumber * testNumberMultiplier;
        }

        return ordDigits;
    }

    static unsigned int ord_digits_from_top(const unsigned long long testBound, const unsigned int testBoundLen) {
        const unsigned long long baseMinTestOrdNumber = ord_digit(testBoundLen);

        unsigned int ordDigits = 0;

        for (int i = 9; baseMinTestOrdNumber * i >= testBound; i--) {
            ordDigits++;
        }

        return ordDigits;
    }

    static unsigned int ord_digits_from_bottom(const unsigned long long testBound, const unsigned int testBoundLen) {
        const unsigned long long baseMaxTestOrdNumber = ord_digit(testBoundLen);

        unsigned int ordDigits = 0;

        for (int i = 1; baseMaxTestOrdNumber * i <= testBound; i++) {
            ordDigits++;
        }

        return ordDigits;
    }

    static unsigned long long ord_digit(unsigned int len) {
        static const unsigned long long lookup[]{
                1LL,
                11LL,
                111LL,
                1111LL,
                11111LL,
                111111LL,
                1111111LL,
                11111111LL,
                111111111LL,
                1111111111LL,
                11111111111LL,
                111111111111LL,
                1111111111111LL,
                11111111111111LL,
                111111111111111LL,
                1111111111111111LL,
                11111111111111111LL,
                111111111111111111LL,
                1111111111111111111LL
        };

        return lookup[len - 1];
    }
};

int main() {
    unsigned long long minTestBound, maxTestBound;

    std::cin >> minTestBound >> maxTestBound;

    std::cout << Solution::maxTests(minTestBound, maxTestBound) << std::endl;

    return 0;
}
