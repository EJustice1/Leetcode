class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> returnVect(n + 1);

        for (int i = 0; i <= n; ++i)
        {
            int temp = i;
            while (temp > 0)
            {  
                returnVect[i] += (temp % 2 == 1);
                temp = temp >> 1;
            }
        }
        return returnVect;
    }
};