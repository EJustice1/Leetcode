class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i = 0;
        int j = height.size() - 1;

        int maxVolume = (j - i) * min(height[i], height[j]);

        int ih = height[i];
        int jh = height[j];

        while (i < j)
        {
            int volume = (j - i) * min(height[i], height[j]);
            maxVolume = max(maxVolume, volume);
            ih = height[i];
            jh = height[j];

            while (height[i] >= height[j] && i < j)
            {
                if (jh < height[j])
                {
                    break;
                }
                --j;
            }
            volume = (j - i) * min(height[i], height[j]);
            maxVolume = max(maxVolume, volume);
            jh = height[j];
            while (height[i] < height[j] && i < j)
            {
                if (ih < height[i])
                {
                    break;
                }
                ++i;
            }
            
        }
        return maxVolume;
    }
};