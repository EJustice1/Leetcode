class Solution {
public:
    int divide(int dividend, int divisor) {
        bool differentSign = (dividend < 0) != (divisor < 0);
        int count = 0;
        if (dividend == divisor)
            return 1;
        long num = dividend >= 0 ? dividend : (long)dividend * -1;
        long denom = divisor >= 0 ? divisor : (long)divisor * -1;
        if (denom == 1) 
        {
            if (num <= INT_MAX)
                return differentSign ? -1 * num : num;
            else
                return differentSign ? INT_MIN : INT_MAX;
        }

        while (num >= denom)
        {
            int i = 0;
            while (num >= (denom<<(i + 1)) )
                ++i;
            num -= denom<<i;
            count += 1<<i;
        }

        return differentSign ? -1 * count : count;
    }
};