class Solution {
public:
    int myAtoi(string s) {
        const short length = s.length();
        bool positive = true;
        long num = 0;
        short i = 0;

        for (; i < length; ++i) {
            char& c = s[i];
            if (c >= '0' && c <= '9') {
                break;
            } else if (c == '-') {
                positive = false;
                ++i;
                break;
            } else if (c == '+') {
                ++i;
                break;
            } else if (c != ' ')
                return 0;
        }

        for (; i < length; ++i) {
            char& c = s[i];
            if (c < '0' || c > '9')
                break;

            num = (10 * num) + (c - '0');
            if (num > INT_MAX) {
                if (positive)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }

        return (positive ? 1 : -1) * num;
    }
};