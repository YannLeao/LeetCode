#include <vector>

class Solution {
public:
    int findMiddleIndex(std::vector<int>& nums) {
        std::vector<int> sumLeft(nums.size());
        int sum = 0;
        int result = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sumLeft[i] = sum;
            sum += nums[i];
        }

        sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (sum == sumLeft[i]) result = i;
            sum += nums[i];
        }
        return result;
    }
};
