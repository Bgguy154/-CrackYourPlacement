class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         // Implement Floyd's Cycle Finding Algorithm
        int slow = nums[0], fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Find the starting point of the cycle
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};