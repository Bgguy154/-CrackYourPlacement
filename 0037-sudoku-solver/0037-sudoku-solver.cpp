class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int m, int n, vector<unordered_set<char>>& hash_row,
    vector<unordered_set<char>>& hash_col, vector<vector<unordered_set<char>>>& hash_sq){

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                //check if the cell is not empty
                if(board[row][col] != '.') continue;
                //check the possibilities from numbers 1-9
                for(char num = '1'; num <= '9'; num++){
                    //check the 3 given rules -- in the description
                    if(!hash_row[row].count(num) && !hash_col[col].count(num) && 
                    !hash_sq[row/3][col/3].count(num)){
                        //fill the empty cell
                        board[row][col] = num;
                        //store the value in hash
                        hash_row[row].insert(num);
                        hash_col[col].insert(num);
                        hash_sq[row/3][col/3].insert(num);
                        //check the possibility with this number
                        if(backtrack(board, m, n, hash_row, hash_col, hash_sq)){
                            //if any one possibility is true, then
                            return true;
                        }
                        //if placing the number gives false then reset
                        board[row][col] = '.'; // make the cell empty
                        //erase the stored num from the hash
                        hash_row[row].erase(num);
                        hash_col[col].erase(num);
                        hash_sq[row/3][col/3].erase(num);
                    }
                }
                //if there's no possibility then return false and backtrack --- so that we can go back and check the possibility with the next number
                return false;
            }
        }
        //if the sudoku is valid then 
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        const int m = 9;
        const int n = 9;
        //declare some data structure like hash to store values
        vector<unordered_set<char>> hash_row(9);
        vector<unordered_set<char>> hash_col(9);
        vector<vector<unordered_set<char>>> hash_sq(3, vector<unordered_set<char>>(3));

        //store the given input values in the hash
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                //if the cell is empty then skip
                if(board[row][col] == '.') continue;
                //else store the value in hash row
                hash_row[row].insert(board[row][col]);
                //store the value in hash cols
                hash_col[col].insert(board[row][col]);
                //store the value in square
                hash_sq[row/3][col/3].insert(board[row][col]);
            }
        }

        //perform backtracking
        backtrack(board, m, n, hash_row, hash_col, hash_sq);
    }
};