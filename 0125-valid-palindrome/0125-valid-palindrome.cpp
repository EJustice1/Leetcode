class Solution {
public:
    bool isPalindrome(string s) {
        const size_t len = s.length();
        int start = 0;
        int end = len - 1;
        for (; start < end; ++start, --end)
        {
            while (!isalnum(s[end]) && start < end) --end;
            while (!isalnum(s[start]) && start < end) ++start;
            if (tolower(s[start]) != tolower(s[end])) return false;
        }
        return true; 
    }
};