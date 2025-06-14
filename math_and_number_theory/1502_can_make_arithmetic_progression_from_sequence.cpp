#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static bool canMakeArithmeticProgression(std::vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) return false;
        if (arr.size() == 2) return true;

        std::sort(arr.begin(), arr.end());
        int difference = arr[0] - arr[1];

        for (int i = 1; i < arr.size() - 1; ++i)
        {
            if (arr[i] - arr[i + 1] != difference) return false;
        }

        return true;
    }
};

int main()
{
    std::vector<int> arr = {3,77,1};
    std::cout << Solution::canMakeArithmeticProgression(arr) << std::endl;
}
