#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    static std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1 == "1") return num2;
        if (num2 == "1") return num1;

        return (num1.length() > num2.length()) ? Solution::myMultiply(num1, num2)
        : Solution::myMultiply(num2, num1);
    }

private:
    static std::string myMultiply(std::string& big, std::string& small) {
        int n_b = big.length();
        int n_s = small.length();

        std::string result = "0";

        for (int i = n_s - 1; i >= 0; --i)
        {
            std::string temp;
            int carry_in = 0;

            for (int j = n_b - 1; j >= 0; --j)
            {
                int n = (small[i] - '0') * (big[j] - '0') + carry_in;
                temp.push_back((n % 10) + '0');
                carry_in = n / 10;
            }

            if (carry_in != 0) temp.push_back(carry_in + '0');

            std::reverse(temp.begin(), temp.end());
            for (int k = 0; k < n_s - 1 - i; ++k) temp.push_back('0');

            result = Solution::mySum(result, temp);
        }
        return result;
    }

    static std::string mySum(std::string& fator1, std::string& fator2) {
        int n1 = fator1.length();
        int n2 = fator2.length();
        int size = (n1 > n2) ? n1 : n2;

        int carry_in = 0;
        std::string result;
        for (int i = 0; i < size; ++i)
        {
            int int_1 = (n1 - i <= 0) ? 0 : fator1[n1 - 1 - i] - '0';
            int int_2 = (n2 - i <= 0) ? 0 : fator2[n2 - 1 - i] - '0';

            int sum = int_1 + int_2 + carry_in;
            carry_in = sum / 10;
            result.push_back((sum % 10) + '0');
        }
        if (carry_in != 0) result.push_back(carry_in + '0');

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    std::cout << Solution::multiply("999", "999");
}