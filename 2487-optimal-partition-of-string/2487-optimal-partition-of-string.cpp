class Solution {
public:
    int partitionString(string s) {
        int substr = 1;
        bool letters[26] = {false};
        for (char c : s)
        {
            if (letters[c-'a'])
            {
                fill(letters, letters + 26, false);
                ++substr;
            }
            letters[c-'a'] = true;
        }
        return substr;
    }
};