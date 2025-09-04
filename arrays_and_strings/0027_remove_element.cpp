#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int last_pointer = nums.size() - 1;
        int count_value = 0;

        for (int i = 0; i <= last_pointer; i++)
        {
            if (nums[i] == val)
            {
                nums[i] = -1;
                nums[i] = nums[last_pointer];
                i--;
                last_pointer--;
                count_value++;
            }

        }

        return nums.size() - count_value;
    }
};
