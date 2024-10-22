class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         unordered_map<int, bool> d;
        int n = grid.size() * grid.size();
        
        // Calculate the expected sum of numbers from 1 to n
        int s = (n * (n + 1)) / 2;
        int repeated = 0;
        
        // Iterate through the grid
        for (const auto& row : grid) {
            for (int num : row) {
                if (d[num]) {
                    repeated = num;
                } else {
                    d[num] = true;
                    s -= num;
                }
            }
        }
        
        // The remaining value in 's' will be the missing value
        return {repeated, s};
    }
};