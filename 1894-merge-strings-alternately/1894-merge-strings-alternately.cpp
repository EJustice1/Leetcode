class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string returnString = "";

        int i1 = 0;
        int i2 = 0;

        const int w1size = word1.length();
        const int w2size = word2.length();

        while(i1 < w1size || i2 < w2size)
        {
            if (i1 < w1size)
                returnString += word1[i1++];
            if (i2 < w2size)
                returnString += word2[i2++];
            
        }
        return returnString;
    }
};