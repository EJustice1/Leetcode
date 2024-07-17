class Solution {
public:
    int compress(vector<char>& chars) {
        const size_t size = chars.size();
        char lastchar = chars[0];
        int len = 0;

        int writeIndex = 0;
        int readIndex = 0;

        for (; readIndex < size; ++readIndex) {
            if (lastchar != chars[readIndex]) {
                chars[writeIndex++] = lastchar;
                if(len > 1){
                string cnt = to_string(len);
                for(char ch : cnt)
                    chars[writeIndex++] = ch;
            }
                lastchar = chars[readIndex];
                len = 1;
            } else
                ++len;
        }
        chars[writeIndex++] = lastchar;

        if(len > 1){
                string cnt = to_string(len);
                for(char ch : cnt)
                    chars[writeIndex++] = ch;
            }

        return writeIndex;
    }
};