class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        
        int n=heights.size();
        stack<int>st;
        int mA=0;
        
        for(int i=0;i<heights.size();++i){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width=i-st.top()-1;
                mA=max(mA,height*width);
            }
            st.push(i);
        }
        return mA;
    }
};