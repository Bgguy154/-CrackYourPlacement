class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int l=0,h=arr.size()-1;
        // int m,c;
        // while(l<=h){
        //     m=l+(h-l)/2;
        //     if(arr[m]>arr[m-1]&&arr[m]>arr[m+1]){
        //         c=m;
        //         break;
        //     }
        //     else if(arr[m]==arr[m-1] || arr[m]==arr[m+1]){
        //         l++;
        //     }
        //     else if(arr[m]<arr[m-1]){
        //          h--;
        //     }
        //     else {
        //         l++;
        //     }
        // }
        // return c;->runtime error
        
         int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return n - 1;
        
        int s = 0;
        int e = n - 1;

        while(s < e) {
            int mid = s + (e - s) / 2;
            if(nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
};