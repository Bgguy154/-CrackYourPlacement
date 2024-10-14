class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
    std::vector<int> result(n, -1);  // Initialize the result array with -1
    std::stack<int> s;  // Stack to store indices of elements

    // Loop through the array twice to handle the circular array case
    for (int i = 0; i < 2 * n; ++i) {
        // Use modulo to simulate the circular nature of the array
        while (!s.empty() && nums[s.top()] < nums[i % n]) {
            result[s.top()] = nums[i % n];
            s.pop();
        }

        // Push the index only in the first pass (i < n)
        if (i < n) {
            s.push(i);
        }
    }

    return result;
    }
};