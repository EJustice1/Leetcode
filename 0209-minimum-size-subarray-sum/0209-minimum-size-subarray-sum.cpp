class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();

        int left = 0;
        int right = 0;
        int sumOfCurrentWindow = 0;
        int len = INT_MAX;

        for (; right < n; ++right)
        {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target)
            {
                len = min(len, right-left + 1);
                sumOfCurrentWindow -= nums[left++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};