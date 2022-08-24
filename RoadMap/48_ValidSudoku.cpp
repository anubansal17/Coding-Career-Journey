class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            bool arr[9] = {0};
            for(int j=0; j<9; j++) {
                if(!isdigit(board[i][j]))
                    continue;
                if(arr[board[i][j]-'1'])
                    return 0;
                arr[board[i][j]-'1'] = 1;
            }
        }
        for(int j=0; j<9; j++) {
            bool arr[9] = {0};
            for(int i=0; i<9; i++) {
            if(!isdigit(board[i][j]))
                    continue;
                if(arr[board[i][j]-'1'])
                    return 0;
                arr[board[i][j]-'1'] = 1;
            }
        }
        for(int i=0; i<9; i += 3) {
            for(int j=0; j<9; j += 3) {
                bool arr[9] = {0};
                for(int k=i+0; k<3+i; k++) {
                    for(int p=j+0; p <3+j; p++) {
                        if(!isdigit(board[k][p]))
                            continue;
                        if(arr[board[k][p]-'1'])
                            return 0;
                        arr[board[k][p]-'1'] = 1;
                    }
                }
            }
        }
        return 1;
    }
};
