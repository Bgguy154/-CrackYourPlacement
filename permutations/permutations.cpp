class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        do {
            result.push_back(nums);     // Add current permutation
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};