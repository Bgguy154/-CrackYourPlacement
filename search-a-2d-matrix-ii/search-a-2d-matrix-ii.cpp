class Solution {
public:
    
    bool searchHelper(vector<vector<int>>& matrix, int target, int i, int j){
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(i>=m)return false;
        if(j>=n)return searchHelper(matrix,target,i+1,0);
        
        if(matrix[i][j]==target)return true;
        return searchHelper(matrix,target,i,j+1);
        
    }
                      
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       return searchHelper(matrix,target,0,0);
    }
    
};