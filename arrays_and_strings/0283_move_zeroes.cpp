#include <iostream>
#include <vector>

class Solution {
public:
    static void moveZeroes(std::vector<int>& nums) {
        int temp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    if (nums[j] != 0)
                    {
                        temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
            }
        }
        
    }
};

int main()
{
    std::vector<int> nums = {1, 0, 1, 0};
    Solution::moveZeroes(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
