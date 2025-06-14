#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    static std::string tictactoe(std::vector<std::vector<int>>& moves) {
        if (moves.size() < 5) return "Pending";

        std::vector<int> rows(3);
        std::vector<int> columns(3);
        std::vector<int> diags(2);

        for (int i = 0; i < moves.size(); ++i)
        {
            int player = (i % 2 == 0) ? 1 : -1;
            rows[moves[i][0]] += player;
            columns[moves[i][1]] += player;
            if (moves[i][1] == moves[i][0]) diags[0] += player;
            if (moves[i][1] + moves[i][0] == 2) diags[1] += player;
        }

        for (int i = 0; i < rows.size(); ++i)
        {
            if (i < 3)
            {
                if (rows[i] == 3 || columns[i] == 3 || diags[i] == 3) return "A";
                if (rows[i] == -3 || columns[i] == -3 || diags[i] == -3) return "B";
            }

            if (rows[i] == 3 || columns[i] == 3) return "A";
            if (rows[i] == -3 || columns[i] == -3) return "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};

int main()
{
    std::vector<std::vector<int>> matrix =
    {
        {0,0}, {1,1}, {2,0}, {1,0}, {1,2},{2,1},{0,1},{0,2},{2,2}
    };
    std::cout << Solution::tictactoe(matrix) << std::endl;
}
