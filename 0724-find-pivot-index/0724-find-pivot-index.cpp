class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int rightSum = -nums[0];
        for (auto& n : nums)
            rightSum += n;
        
        int leftSum = 0;
        int i = 0;
        while (leftSum != rightSum)
        {
            if (i >= nums.size() - 1)
                return -1;

            leftSum += nums[i];
            rightSum -= nums[++i];

        }
        return i;
    }
};