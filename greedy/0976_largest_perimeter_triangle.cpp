#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i + 1] + nums[i + 2] > nums[i]) return nums[i + 1] + nums[i + 2] + nums[i];
        }
        return 0;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 2, 10};
    std::cout << Solution::largestPerimeter(nums);
}
