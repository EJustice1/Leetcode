class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<uint, bool> dp;
        uint sq = 0;
        for (uint i = 0; sq <= c; ++i)
        {
            dp[sq] = true;
            if (dp.find(c-sq) != dp.end())
                return true;
            sq = i*i;
        }
        return false;
    }
};