class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;          // handle INT_MIN safely
        if (exp < 0) {
            x = 1.0 / x;            // invert base for negative power
            exp = -exp;
        }

        double result = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1) {     // if current bit is 1
                result *= x;
            }
            x *= x;                 // square the base
            exp /= 2;               // move to next bit
        }

        return result;
    }
};

