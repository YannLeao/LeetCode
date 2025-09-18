#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> values;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (values.find(target - nums[i]) != values.end()) return {values[target - nums[i]], i};
            values[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main()
{
    std::vector nums_ = {2, 7, 11, 15};
    std::vector<int> nums = Solution::twoSum(nums_, 9);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;    return 0;
}
