class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;
        if (x == -1)
            return (n % 2) * -2 + 1;
        if (n < 0) {
            if (n == INT_MIN)
                n = INT_MAX;
            else
                n *= -1;
            return 1 / myPow(x, n);
        }

        // n is positive
        uint currPow = 1;
        double num = x;

        while (currPow + currPow <= n)
        {
            currPow += currPow;
            num = num * num;
        }

        return num * myPow(x, n - currPow);
    }
};