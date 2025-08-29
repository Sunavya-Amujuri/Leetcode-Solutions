class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                char ch = board[r][c];
                if(ch == '.') continue;

                for(int cc=c+1; cc<9; cc++){
                    if(board[r][cc] == ch) return false;
                }

                for(int rr=r+1; rr<9; rr++){
                    if(board[rr][c] == ch) return false;
                }

                int br = (r / 3) * 3;
                int bc = (c / 3) * 3;
                for(int i=br; i<br+3; i++){
                    for(int j=bc; j<bc+3; j++){
                        if(!(i==r && j==c) && board[i][j] == ch) return false;
                    }
                }
            }
        }
        return true;  
    }
};