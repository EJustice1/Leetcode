class Solution {
public:
    int kthFactor(int n, int k) {
        
        int factors = 0;
        for (int i = 1; (i + i) <= n; ++i)
        {
            if (n%i == 0)
                ++factors;
            if (factors == k)
                return i;
        }

        if (factors + 1 == k)
            return n;

        return -1;
    }
};