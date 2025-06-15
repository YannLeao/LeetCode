// by Newton-Raphson

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        long long y = x / 2;
        while (y * y > x)
        {
            y = (y + x / y)  / 2;
            if ((y*y < x) && ((y+1)*(y+1) > x)) return y;
        }
        return y;
    }
};