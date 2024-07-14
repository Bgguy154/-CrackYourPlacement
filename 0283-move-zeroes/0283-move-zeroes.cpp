class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Initialize j to 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap nums[i] with nums[j]
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++; // Increment j only when nums[i] is non-zero
            }
        }
    }
};
