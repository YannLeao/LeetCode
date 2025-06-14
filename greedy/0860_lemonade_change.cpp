#include <iostream>
#include <vector>

class Solution {
public:
    static bool lemonadeChange(std::vector<int>& bills) {
        std::vector<int> count_bills = {0, 0, 0};

        for (auto bill : bills)
        {
            if (bill == 5) count_bills[0]++;
            else if (bill == 20)
            {
                count_bills[2]++;
                if (count_bills[1] == 0) count_bills[0] -= 3;
                else
                {
                    count_bills[0]--;
                    count_bills[1]--;
                }
                if (count_bills[0] < 0 || count_bills[1] < 0) return false;
            }
            else
            {
                count_bills[0]--;
                count_bills[1]++;
                if (count_bills[0] < 0) return false;
            }

        }

        return true;
    }
};

int main()
{
    std::vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    std::cout << Solution::lemonadeChange(bills);
}
