class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        
        vector<int> prev=getRow(rowIndex-1);
        vector<int> current(rowIndex+1);
        
        current[0]=current[rowIndex]=1;
        
        for(int i=1;i<rowIndex;++i){
            current[i]=prev[i-1]+prev[i];
        }
        return current;
    }
};