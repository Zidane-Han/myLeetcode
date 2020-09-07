class Solution {
private:
    const int LEN = 9;
    
    bool isValidRow(int p, vector<vector<char>>& board) {
        vector<char> v;
        unordered_set<char> s;
        for (int i = 0; i < LEN; i++) {
            char tmp = board[p][i];
            if (tmp == '.') continue;
            v.push_back(tmp);
            s.insert(tmp);
        }
        return v.size() == s.size();
    }
    
    bool isValidCol(int p, vector<vector<char>>& board) {
        vector<char> v;
        unordered_set<char> s;
        for (int i = 0; i < LEN; i++) {
            char tmp = board[i][p];
            if (tmp == '.') continue;
            v.push_back(tmp);
            s.insert(tmp);
        }
        return v.size() == s.size();
    }
    
    bool isValidCell(int p, int q, vector<vector<char>>& board) {
        vector<char> v;
        unordered_set<char> s;
        for (int i = p; i < p+3; i++) {
            for (int j = q; j < q+3; j++) {
                char tmp = board[i][j];
                if (tmp == '.') continue;
                v.push_back(tmp);
                s.insert(tmp);
            }
        }   
        return v.size() == s.size();
    }
    

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (int i = 0; i < LEN; i++) {
            if (!isValidRow(i, board))    return false; 
        }
        
        // check cols
        for (int j = 0; j < LEN; j++) {
            if (!isValidCol(j, board))    return false;
        }
        
        // check cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!isValidCell(3*i, 3*j, board))  return false;
            }
        }
            
        return true;
    }
};