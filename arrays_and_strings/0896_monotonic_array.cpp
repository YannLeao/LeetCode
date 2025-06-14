#include <iostream>
#include <vector>

class Solution {
public:
    static bool isMonotonic(std::vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return true;

        bool increasing = false;
        bool decreasing = false;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1]) continue;
            if (nums[i] <= nums[i + 1])
            {
                increasing = true;
                continue;
            }
            decreasing = true;
        }

        return !(increasing && decreasing);
    }
};

int main()
{
    std::vector<int> nums = {6,5,4,4};
    std::cout << Solution::isMonotonic(nums) << std::endl;
}
