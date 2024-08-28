class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int n=arr.size();
        // int l=0,h=n-1,o=0;
        // int m,i;
        // while(k){
        //     m=(l+h)/2;
        //     i=
        //     if(arr[m]!=m-l+1){
        //         k-=(arr[m]-i-l+1);
        //         o=k;
        //         l++;
        //     }
        //     else{
        //         l++;
        //     }
        // }
        // if(o==0)o+=n+k;
        // return o;
        
        int ind = 0, ans = 1, n = arr.size();
        int count = 0;
        while (count != k) {
            if ((ind < n && ans < arr[ind]) || ind >= n) count++;
            if (ind < n && ans == arr[ind]) ind++;
            ans++;
        }
        return ans-1;
    }
};