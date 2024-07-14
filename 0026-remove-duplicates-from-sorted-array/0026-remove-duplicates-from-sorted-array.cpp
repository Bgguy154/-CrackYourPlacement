class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.empty()) return 0; // If the array is empty, return 0
        
        int k = 1; // Initialize the count of unique elements
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous one
            if (nums[i] != nums[i - 1]) {
                // Move the unique element to position k
                nums[k] = nums[i];
                k++; // Increment k to reflect the new count of unique elements
            }
        }
        
        return k;
    }
};