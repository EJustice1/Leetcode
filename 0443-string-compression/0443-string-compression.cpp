class Solution {
public:
    int compress(vector<char>& chars) {
        char lastchar = chars[0];
        int len = 0;
        int writeIndex = 0;

        for (char c : chars) {
            if (lastchar != c) {
                chars[writeIndex++] = lastchar;
                if (len > 1) {
                    string cnt = to_string(len);
                    for (char ch : cnt)
                        chars[writeIndex++] = ch;
                }
                lastchar = c;
                len = 1;
            } else
                ++len;
        }
        chars[writeIndex++] = lastchar;

        if (len > 1) {
            string cnt = to_string(len);
            for (char ch : cnt)
                chars[writeIndex++] = ch;
        }

        return writeIndex;
    }
};