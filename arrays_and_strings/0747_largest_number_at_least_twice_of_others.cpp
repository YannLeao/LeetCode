#include <iostream>
#include <vector>

class Solution {
public:
    static int dominantIndex(std::vector<int>& nums) {
        int indexMax = 0;
        int max = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > max)
            {
                indexMax = i;
                max = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (max < nums[i] * 2 && i != indexMax) return -1;
        }
        return indexMax;
    }
};

int main()
{
    std::vector<int> nums = {2,0,0,3};
    std::cout << Solution::dominantIndex(nums) << std::endl;
}