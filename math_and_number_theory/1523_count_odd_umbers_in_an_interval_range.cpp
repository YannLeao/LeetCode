#include <iostream>

class Solution {
public:
    static int countOdds(int low, int high) {
        if (((low + high) % 2 == 1) || (low % 2 == 1 && high % 2 == 1)) return (high - low) / 2 + 1;
        return (high - low) / 2;
    }
};

int main()
{
    std::cout << Solution::countOdds(8, 11);
}