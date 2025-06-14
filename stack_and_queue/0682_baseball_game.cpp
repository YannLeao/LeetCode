#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    static int calPoints(std::vector<std::string>& operations) {
        std::stack<int> stack;

        for (const auto & operation : operations)
        {
            if (operation == "C") stack.pop();
            else if (operation == "D") stack.push(stack.top() * 2);
            else if (operation == "+")
            {
                int num = stack.top();
                stack.pop();
                int sum = stack.top() + num;

                stack.push(num);
                stack.push(sum);
            }
            else stack.push(std::stoi(operation));
        }

        int result = 0;
        int size = stack.size();
        for (int i = 0; i < size; ++i)
        {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};

int main()
{
    std::vector<std::string> operations = {"5","2","C","D","+"};
    std::cout << Solution::calPoints(operations) << std::endl;
}