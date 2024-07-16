class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int operations = 0;
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            int summed = nums[i] + nums[j];


            if (summed == k)
            {
                ++operations;
                ++i;
                --j;
            }
            else if (summed > k)
            {
                --j;
            }
            else //summed < k
            {
                ++i;
            }
        }
        return operations;
    }
};