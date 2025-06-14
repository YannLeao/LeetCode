#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    static bool isRobotBounded(std::string instructions) {
        std::vector<int> position = {0, 0};
        std::vector<std::pair<int, int>> directions = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };
        int direction = 0;
        for (auto instruction : instructions)
        {
            if (instruction == 'G')
            {
                position[0] += directions[direction].first;
                position[1] += directions[direction].second;
            }
            else if (instruction == 'R') direction = (direction + 1) % 4;
            else direction = (direction + 3) % 4;
        }
        return ((position[0] == 0 && position[1] == 0) || direction != 0);
    }
};

int main()
{
    std::cout << Solution::isRobotBounded("GGLL") << std::endl;
}