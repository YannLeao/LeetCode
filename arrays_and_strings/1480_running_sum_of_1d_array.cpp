#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        int sum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += sum;
            sum = nums[i];
        }
        return nums;
    }
};
