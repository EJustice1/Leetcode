class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = (a | b) ^ c;
        char shiftNum = 0;
        char ones = 0;
        while (d >> shiftNum)
        {
            if (d & (1 << shiftNum))
            {
                if ((c + (1 << shiftNum)) & (1 << shiftNum))
                    ones += ((a & (1 << shiftNum)) + (b & (1 << shiftNum))) >> shiftNum;
                else
                    ++ones;
            }
            ++shiftNum;
        }
    
        return ones;
    }
};