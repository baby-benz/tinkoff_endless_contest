#include <iostream>

class Solution {
public:
    static unsigned int findMinFlights(const unsigned int n, const unsigned int *empFloors, const unsigned int minsToLeave, const unsigned int leavingEmpNum) {
        const unsigned int leavingEmpFloor = empFloors[leavingEmpNum - 1];
        const unsigned int floorsTotal = empFloors[n - 1] - empFloors[0];
        const unsigned int floorsDown = leavingEmpFloor - empFloors[0];
        const unsigned int floorsUp = empFloors[n - 1] - leavingEmpFloor;

        if (floorsDown <= minsToLeave || floorsUp <= minsToLeave) {
            return floorsTotal;
        } else if (floorsDown < floorsUp) {
            return floorsDown * 2 + floorsUp;
        } else {
            return floorsUp * 2 + floorsDown;
        }
    }
};

int main() {
    unsigned int n, minsToLeave, leavingEmpNum;

    std::cin >> n >> minsToLeave;

    auto *empFloors = new unsigned int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> empFloors[i];
    }

    std::cin >> leavingEmpNum;

    std::cout << Solution::findMinFlights(n, empFloors, minsToLeave, leavingEmpNum) << std::endl;

    free(empFloors);

    return 0;
}
