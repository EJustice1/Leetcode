class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;
        short mult = 10;
        x = abs(x);
        long reversed = 0;
        while (x > 0)
        {
            reversed = reversed * mult + (x%10);
            x *= .1;

            if (reversed >= INT_MAX)
                return 0;
        }

        
        
        return negative ? -1 * reversed : reversed;
    }
};