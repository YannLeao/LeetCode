#include <iostream>
#include <vector>

// Improves solution: runtime O(n)
class Solution {
public:
    static void duplicateZeros(std::vector<int>& arr) {
        int count = 0;
        for (int i : arr) if (i == 0) count++;

        int size = arr.size();

        for (int i = size - 1; i >= 0; i--)
        {
            if (arr[i] == 0) count--;

            int pointer = i + count;
            if (pointer < size) arr[pointer] = arr[i];
            if (arr[i] == 0 && pointer + 1 < size) arr[pointer + 1] = 0;
        }
    }
};

// My first solution: runtime O(n^2)
/*
class Solution {
public:
    static void duplicateZeros(std::vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i] == 0)
            {
                int value = arr[i];
                i++;

                for (int j = i; j <= arr.size() - 1; ++j)
                {
                    int temp = arr[j];
                    arr[j] = value;
                    value = temp;
                }
            }
        }
    }
};
*/

int main()
{
    std::vector<int> nums = {1,0,2,3,0,4,5,0};
    Solution::duplicateZeros(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;    return 0;
}