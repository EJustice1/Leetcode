class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int row = 0; row < 9; ++row) { //0-8
            for (int col = 0; col < 9; ++col) { //0-8
                int num = board[row][col] - '0' - 1; //0-8

                if (num < 0 || num > 8)
                    continue;

                if (rows[row][num])
                    return false;
                rows[row][num] = true;

                if (cols[col][num])
                    return false;
                cols[col][num] = true;

                int box = (3 * (row / 3)) + ((col/3) % 3);
                if (boxes[box][num])
                    return false;
                boxes[box][num] = true;
            }
        }
        return true;
    }
};