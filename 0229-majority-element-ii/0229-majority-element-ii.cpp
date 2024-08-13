// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
       
//          std::sort(nums.begin(), nums.end());
//          vector<int>asn;
//         if(nums.size()==1)asn.push_back(nums[0]);
//         int c=0;
//         // Return the middle element
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]){
//                 c++;
//             }
//         if(c>=nums.size()/3){asn.push_back(nums[i]);c=0;}
//     }
//         return asn;
//     }
// };

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1; // Initialize with two different numbers
        
        // First pass: Find potential candidates for majority elements
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Second pass: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }
        
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);
        
        return ans;
    }
};
