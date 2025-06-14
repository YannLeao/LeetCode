# include <cmath>

// Nesse problema ocorreu um erro em std::abs(n). Pois tentava modificar o sinal do limite do
// 'int', que vai de -2147483648 a 2147483647, ou seja, não há 2147483648!

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0 || x == 1) return 1;
        if (x == -1) return (n % 2 == 0) ? 1 : -1;

        long exp = std::abs((long) n);
        double result = 1.0;

        while(exp > 0)
        {
            if (exp % 2 == 1) result *= x;
            x *= x;
            exp /= 2;
        }
        return (n > 0) ? result : 1/result;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (x == 0) return 0;
//         if (n == 0 || x == 1) return 1;
//         if (x == -1) return (n % 2 == 0) ? 1 : -1;
//
//         double result = 1.0;
//         long safe_abs = std::abs((long) n);
//         for (long i = 0; i < safe_abs; ++i) result *= x;
//
//         if (n < 0) return 1 / result;
//         return result;
//     }
// };