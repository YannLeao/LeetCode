#include <algorithm>
#include <vector>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        if (nums.size() < 3) return nums[nums.size() - 1];
        else return nums[2];
    }
};
