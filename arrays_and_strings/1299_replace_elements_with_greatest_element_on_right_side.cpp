#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    static std::vector<int> replaceElements(std::vector<int>& arr) {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0 ; --i) max = std::max(max, std::exchange(arr[i], max));
        return arr;
    }
};


// Version O(N^2)
// class Solution {
// public:
//     static std::vector<int> replaceElements(std::vector<int>& arr) {
//         for (int i = 0; i < arr.size() - 1; ++i)
//         {
//             int max = 0;
//             for (int j = i + 1; j <= arr.size() - 1; ++j)
//             {
//                 max = std::max(max, arr[j]);
//             }
//             arr[i] = max;
//         }
//
//         arr[arr.size() - 1] = -1;
//         return arr;
//     }
// };

int main()
{
    std::vector<int> nums = {17,18,5,4,6,1};
    nums = Solution::replaceElements(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;    return 0;
}