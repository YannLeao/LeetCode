#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int write_ptr = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
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
