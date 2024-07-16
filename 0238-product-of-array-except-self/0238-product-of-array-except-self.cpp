class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        vector<int> returnVector(size);

        int rightNum = 1;
        int leftNum = 1;

        for (int i = size - 1; i >= 0; --i)
        {
            returnVector[i] = rightNum;
            rightNum *= nums[i];
        }

        for (int i = 0; i < size; ++i)
        {
            int temp = nums[i];
            nums[i] = leftNum;
            leftNum *= temp;
        }

        for (int i = 0; i < size; ++i)
        {
            returnVector[i] = returnVector[i] * nums[i];
        }
        return returnVector;
    }
};