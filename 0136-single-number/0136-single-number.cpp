class Solution {
public:
    int singleNumber(vector<int>& nums) {
      // int result = 0;
      //   for(int num : nums) {
      //       result ^= num;  // XOR every element with result
      //   }
      //   return result;
        

        
//         Given an array where every element appears twice except for one, we can leverage these properties:

//     Step 1: Initialize a variable result to 0.
//     Step 2: XOR each element of the array with result.
//     Step 3: Due to the properties of XOR, all numbers that appear twice will cancel each other out because x⊕x=0x⊕x=0.
//     Step 4: The only number left in result will be the one that appears exactly once because 0⊕y=y0⊕y=y.

// Example Walkthrough:

// Consider the array nums = [4, 1, 2, 1, 2].

//     Initial result = 0.
//     XORing elements in sequence:
//         result = 0 ^ 4 = 4
//         result = 4 ^ 1 = 5
//         result = 5 ^ 2 = 7
//         result = 7 ^ 1 = 6
//         result = 6 ^ 2 = 4

// At the end of the loop, result holds the value 4, which is the single number in the array.
// Summary:

//     The XOR operation allows us to efficiently cancel out the numbers that appear twice, leaving us with the single number that appears only once.
//     This approach is optimal with a linear runtime O(n)O(n) and constant space O(1)O(1), fulfilling the problem's constraints.
        
        
        
        
        
        std::unordered_map<int, int> countMap;
        
        // Count the occurrences of each element
        for (int num : nums) {
            countMap[num]++;
        }
        
        // Find the element with count 1
        for (auto& entry : countMap) {
            if (entry.second == 1) {
                return entry.first;
            }
        }
        
        return -1; 
    }
};