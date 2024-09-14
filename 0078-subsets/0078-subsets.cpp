class Solution {
public:
//     vector<vector<int>> ans;
//     vector<vector<int>> subsets(vector<int>& nums) {
//           ans.clear();
//         queue<pair<vector<int>, int>> q;
//         q.push({{}, 0});
//         while(!q.empty()){
//             auto k = q.front();
//             q.pop();
//             auto vec = k.first;
//             auto idx = k.second;
//             if(idx >= nums.size()){
//                 ans.push_back(vec);
//             }else{
//                 q.push({vec, idx + 1});
//                 vec.push_back(nums[idx]);
//                 q.push({vec, idx + 1});
//             }
//         }

//         return ans;
    
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>&nums){
ans.clear();
    queue<pair<vector<int>,int>>q;
    q.push({{},0});
        while(!q.empty()){
            auto k=q.front();
            q.pop();
            auto vec=k.first;
            auto idx=k.second;
            if(idx>=nums.size()){
                ans.push_back(vec);
            }
            else{
                q.push({vec,idx+1});
                vec.push_back(nums[idx]);
                q.push({vec,idx+1});
            }
        }
        return ans;
    }
};