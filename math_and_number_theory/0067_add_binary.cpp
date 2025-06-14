#include <iostream>
#include <string>

class Solution {
public:
    static std::string addBinary(std::string a, std::string b) {
        int n_a = a.length();
        int n_b = b.length();
        int size = (n_a >= n_b) ? n_a : n_b;

        std::string result;
        int carry_in = 0;
        int sum = 0;

        for (int i = 0; i < size; ++i)
        {
            int int_a = (n_a - i <= 0) ? 0 : a[n_a - 1 - i] - '0';
            int int_b = (n_b - i <= 0) ? 0 : b[n_b - 1 - i] - '0';

            sum = (int_a ^ int_b) ^ carry_in;
            carry_in = (int_a & int_b) | (int_a ^ int_b) & carry_in;

            char c = sum + '0';
            result.insert(0, 1, c);
        }
        if (carry_in == 1) result.insert(0, 1, '1');
        return result;
    }
};

int main()
{
    std::cout << Solution::addBinary("1010", "1011");
}
