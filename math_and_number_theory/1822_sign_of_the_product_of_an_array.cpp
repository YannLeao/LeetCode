#include <iostream>
#include <vector>

class Solution {
public:
    static int arraySign(std::vector<int>& nums) {
        int count = 0;
        for (auto num : nums)
        {
            if (num == 0) return 0;
            if (num < 0) count++;
        }

        if (count % 2 == 1) return -1;
        return 1;

    }

    // static int arraySign(std::vector<int>& nums) {
    //     int product = 1;
    //     for (auto num : nums)
    //     {
    //         product *= num;
    //     }
    //     return Solution::signFunc(product);
    // }
    //
    // static int signFunc(int x)
    // {
    //     if (x > 0) return 1;
    //     if (x < 0) return -1;
    //     return 0;
    // }
};

int main()
{
    std::vector<int> nums = {-1,-2,-3,-4,3,2,1};
    std::cout << Solution::arraySign(nums) << std::endl;
}