#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> applyOperations(std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                nums[i] = 0;
                nums[i - 1] *= 2;
            }
        }

        int write_ptr = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                int temp = nums[write_ptr];
                nums[write_ptr] = nums[i];
                nums[i] = temp;
                write_ptr++;
            }
        }

        return nums;
    }
};

int main()
{
    std::vector<int> nums = {1,2,2,1,1,0};
    nums = Solution::applyOperations(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}