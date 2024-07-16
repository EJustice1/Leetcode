class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int totalSize = nums1.size() + nums2.size() - 2;
        const int size1 = nums1.size();
        const int size2 = nums2.size();

        size_t index1 = 0;
        size_t index2 = 0;

        while (index1+index2 < totalSize/2.0)
        {
            if (index1 == size1)
                ++index2;
            else if (index2 == size2)
                ++index1;
            else if (nums1[index1] < nums2[index2])
                ++index1;
            else
                ++index2;
        }

        int num1;

         if (index1 == size1)
                num1 = nums2[index2++];
            else if (index2 == size2)
                num1 = nums1[index1++];
            else if (nums1[index1] < nums2[index2])
                num1 = nums1[index1++];
            else
                num1 = nums2[index2++];

        if (totalSize % 2 == 0)
        {
            int num2;

            if (index1 == size1)
                num2 = nums2[index2++];
            else if (index2 == size2)
                num2 = nums1[index1++];
            else if (nums1[index1] < nums2[index2])
                num2 = nums1[index1++];
            else
                num2 = nums2[index2++];

            return (num1 + num2)/2.0;
        }

        return num1;
    }
};