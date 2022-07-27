    #include <iostream>
    #include <cmath>
    #include <set>

    class Solution {
    public:
        static unsigned long long
        findMaxSumIncrease(const unsigned int *nums, const unsigned int numsCount, const unsigned int operationsAllowed) {
            std::multiset<unsigned int, std::greater<>> sumAdditions;

            for (unsigned int i = 0; i < numsCount; i++) {
                std::string strNum = std::to_string(nums[i]);
                for (unsigned int j = 0; j < strNum.size(); j++) {
                    const unsigned int curIncrease = (9 - (strNum[j] - '0')) * pow(10.0, strNum.size() - j - 1);
                    if (curIncrease > 0) {
                        sumAdditions.insert(curIncrease);
                    }
                }
            }

            unsigned long long maxIncrease = 0;
            auto it = sumAdditions.begin();

            for (unsigned int i = 0; i < operationsAllowed && i < sumAdditions.size(); i++, it++) {
                maxIncrease += *it;
            }

            return maxIncrease;
        }
    };

    int main() {
        unsigned int numsCount;
        int operationsAllowed;

        std::cin >> numsCount >> operationsAllowed;

        auto *nums = new unsigned int[numsCount];

        for (unsigned int i = 0; i < numsCount; i++) {
            std::cin >> nums[i];
        }

        std::cout << Solution::findMaxSumIncrease(nums, numsCount, operationsAllowed) << std::endl;

        delete[] nums;

        return 0;
    }
