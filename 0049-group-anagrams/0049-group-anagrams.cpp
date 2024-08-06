class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string cur = strs[i];
            sort(cur.begin(),cur.end());
            mp[cur].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto el:mp)
//             The syntax for(auto el:mp) is a C++11 (and later) range-based for loop. This loop is used to iterate over all elements in a container, such as a map (std::map), which is often abbreviated as mp. Here’s a breakdown of its components:

//     auto: This keyword automatically deduces the type of el based on the type of elements in the container mp.
//     el: This is the loop variable that will take the value of each element in the container as the loop iterates.
//     mp: This is the container being iterated over
        {
            result.push_back(el.second);
        }
        return result;
    }
};