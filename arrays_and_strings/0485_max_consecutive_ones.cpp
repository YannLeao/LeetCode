#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int maxOnes = 0;
        int currentOnes = 0;

        for (int i : nums)
        {
            if (i == 1) currentOnes++;
            else
            {
                maxOnes = std::max(maxOnes, currentOnes);
                currentOnes = 0;
            }
        }

        return std::max(maxOnes, currentOnes);
    }
};
