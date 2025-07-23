/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let count=0;
    const board=[];
    
    function isSafe(row,col){
    for(let i=0;i<row;i++){
        if(board[i]===col || Math.abs(board[i]-col)===Math.abs(i-row)){
            return false;
        }
    }
        return true;
    }
    
    function solve(row){
        if(row===n){
            count++;
        }
        for(let col=0;col<n;col++){
          if (isSafe(row,col)){
              board[row]=col;
              solve(row+1);
          }   
        }
    }
    solve(0);
    return count;
};