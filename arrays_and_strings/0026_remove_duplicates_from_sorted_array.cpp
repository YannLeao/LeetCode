#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int first_pointer = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[first_pointer - 1])
            {
                nums[first_pointer] = nums[i];
                first_pointer++;
            }
        }
        
        return first_pointer;
    }
};
