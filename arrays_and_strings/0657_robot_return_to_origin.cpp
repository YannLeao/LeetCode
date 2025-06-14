#include <string>

class Solution {
public:
    static bool judgeCircle(std::string moves) {
        int abscissas = 0;
        int coordinates = 0;
        for (auto move : moves)
        {
            if (move == 'R') abscissas++;
            else if (move == 'L') abscissas--;
            else if (move == 'U') coordinates++;
            else coordinates--;
        }
        return (abscissas == 0 && coordinates == 0);
    }
};
