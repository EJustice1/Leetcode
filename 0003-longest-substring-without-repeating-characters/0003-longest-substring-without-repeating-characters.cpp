class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const ushort length = s.length();
        if (length == 0)
            return 0;
        int longest = 1;
        unordered_map<char, int> letters;
        int furthestBack = 0;
        for (int i = 0; i < length; ++i)
        {   
            if(letters.find(s[i]) != letters.end())
                furthestBack = max(furthestBack, letters[s[i]] + 1);
            letters[s[i]] = i;
            longest = max(i-furthestBack+1, longest);
        }
        longest = max(length-furthestBack, longest);
        return longest;
    }
};