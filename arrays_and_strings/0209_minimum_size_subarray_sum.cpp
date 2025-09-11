#include <iostream>
#include <limits.h>
#include <vector>

class Solution {
public:
    static int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int right = 0;
        long long sum = 0;
        int minLeght = INT_MAX;

        while (right < nums.size())
        {
            sum += nums[right];
            right++;

            while (sum >= target)
            {
                minLeght = std::min(minLeght, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return (minLeght == INT_MAX) ? 0 : minLeght;
    }
};

int main()
{
    std::vector<int> nums = {2,3,1,2,4,3};
    std::cout << Solution::minSubArrayLen(7, nums) << std::endl;
}
