class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int result = 0;
        for(int num : nums) {
            result ^= num;  // XOR every element with result
        }
        return result;
    }
};