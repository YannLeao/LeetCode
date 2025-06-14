#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size() -1;
        digits[n]++;

        for (int i = n; i > 0; --i)
        {
            if (digits[i] >= 10)
            {
                digits[i] %= 10;
                digits[i - 1]++;
            }
        }

        if (digits[0] >= 10)
        {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main()
{
    std::vector<int> nums_ = {9, 9, 9, 9};
    std::vector<int> nums = Solution::plusOne(nums_);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
