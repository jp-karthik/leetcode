class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        
        //row checking
        for (int i = 0; i < n; i++) {
            map<char,int> m;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    m[board[i][j]]++;
                }
            }
            for (auto e : m) {
                if (e.second > 1) {
                    return false;
                }
            }
        }
        
        //column checking
        for (int j = 0; j < n; j++) {
            map<char,int> m;
            for (int i = 0; i < n; i++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    m[board[i][j]]++;
                }
            }
            for (auto e : m) {
                if (e.second > 1) {
                    return false;
                }
            }
        }
        
        // cell checking
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                map<char,int> m;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (board[i + x][j + y] == '.') {
                            continue;
                        } else {
                            m[board[i + x][j + y]]++;
                        }
                    }
                }
                for (auto e : m) {
                    if (e.second > 1) return false;
                }
            }
        }
        
        return true;
    }
};