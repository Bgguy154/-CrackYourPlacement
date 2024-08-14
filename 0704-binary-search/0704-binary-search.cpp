class Solution {
public:
    int search(vector<int>& arr, int target) {
        int i=0,j=arr.size()-1;
        int mid;
        int x=-1;
        while(i<=j){
            mid=(i+j)/2;
            if(arr[mid]==target){
                x=mid;
                return mid;
            }
            else if(arr[mid]<target){
                i++;
            }
            else j--;
        }
        if(x!=-1){
        return mid;
        }
        return x;
    }
};