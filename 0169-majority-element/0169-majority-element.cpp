class Solution {
public:
    int majorityElement(vector<int>& nums) {
       std::sort(nums.begin(), nums.end());
        
        // Return the middle element
        return nums[nums.size() / 2];
    }
};
