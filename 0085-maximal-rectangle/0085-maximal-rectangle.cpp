class Solution {
public:

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    
    int ans = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    
    // Iterate through each row
    for(int i = 0; i < rows; i++) {
        // Update the heights array based on the current row
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == '0') {
                heights[j] = 0;
            } else {
                heights[j] += 1;
            }
        }
        
        // Calculate the largest rectangle area in the updated heights array (in-place)
        stack<int> st;
        for(int j = 0; j <= cols; j++) {
            int currHeight = (j == cols) ? 0 : heights[j];
            while(!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(j);
        }
    }
    
    return ans;
}

};