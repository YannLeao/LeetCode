class Solution {
public:
    bool isPerfectSquare(int num) {
        int count = 0;
        while (num > 0)
        {
            num -= (2 * count + 1);
            count++;
            if (num == 0) return true;
        }
        return false;
        
    }
};