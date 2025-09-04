#include <iostream>
#include <vector>

class Solution {
public:
    static bool validMountainArray(std::vector<int>& arr) {
        if (arr.size() < 3) return false;

        int size = arr.size() - 1, i = 0;
        while (arr[i] < arr[i + 1] && i < size) i++;

        if (i == 0 || i == size) return false;
        while (i < size && arr[i] > arr[i + 1]) i++;

        if (i == size) return true;
        else return false;
    }
};
int main()
{
    std::vector<int> nums = {0,1,2};
    std::cout << Solution::validMountainArray(nums) << std::endl;
}