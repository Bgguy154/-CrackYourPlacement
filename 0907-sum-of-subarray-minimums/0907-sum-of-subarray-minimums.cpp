class Solution {
public:

const int MOD = 1e9 + 7;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    
    // Arrays to store the number of subarrays the current element is the minimum in
    vector<int> left(n), right(n);

    // Monotonic stacks for calculating left and right
    stack<pair<int, int>> s1, s2;
    
    // Calculate left, which represents the number of subarrays ending at arr[i] where arr[i] is the minimum
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (!s1.empty() && s1.top().first > arr[i]) {
            count += s1.top().second;
            s1.pop();
        }
        left[i] = count;
        s1.push({arr[i], count});
    }
    
    // Calculate right, which represents the number of subarrays starting at arr[i] where arr[i] is the minimum
    for (int i = n - 1; i >= 0; i--) {
        int count = 1;
        while (!s2.empty() && s2.top().first >= arr[i]) {
            count += s2.top().second;
            s2.pop();
        }
        right[i] = count;
        s2.push({arr[i], count});
    }
    
    // Now calculate the result using the contribution formula
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result = (result + (long long) arr[i] * left[i] * right[i]) % MOD;
    }
    
    return result;
    }
};