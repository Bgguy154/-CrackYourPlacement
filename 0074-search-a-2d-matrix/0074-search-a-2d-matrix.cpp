class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m=matrix.size();
        // int n=matrix[0].size();
        // int h=0,k=0;
        // while(h<=m && k<=n){
        //     int mid=(h+m)/2;
        //     int m2=(k+n)/2;
        //     if(matrix[mid][m2]==target){
        //         return true;
        //     }
        //     else if(matrix[mid][m2]<target){
        //         m--;
        //         n--;
        //     }
        //     else{
        //         k++;
        //         h++;
        //     }
        // }
        // return false;
        
        int row = matrix.size() ;
        int col = matrix[0].size() ;
        int s = 0 ;
        int e = row*col - 1 ;
        int m = s+(e-s)/2;
        while(s<=e){
            int element = matrix[m/col][m%col];
            if(target == element){
                return 1;
            }
            else if(target <= element){
                e=m-1;
            }
            else {
                s=m+1;
            }
            m = s+(e-s)/2;
        }
        return 0;
    }
};