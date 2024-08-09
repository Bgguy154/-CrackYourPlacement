class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int j;
        // int n=nums.size();
        // while(k--){
        //     j=nums[n-1];
        //     for(int i=n-2;i>=0;i--){
        //         nums[i+1]=nums[i];
        //     }
        //     nums[0]=j;
        // }
        
        

 k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());

// We first calculate the effective rotation amount k by taking the remainder of k when divided by the length of the array. This is because if k is greater than the length of the array, it's equivalent to rotating the array by k % len(nums) steps.
// We then reverse the entire array using the reverse() method.
// Next, we reverse the first k elements by slicing the array from the beginning up to index k (exclusive) and reversing it using reversed(). We assign the reversed result back to this slice.
// Finally, we reverse the remaining elements by slicing the array from index k to the end and reversing it using reversed(). Again, we assign the reversed result back to this slice
    }
};