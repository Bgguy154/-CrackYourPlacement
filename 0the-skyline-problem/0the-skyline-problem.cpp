class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // start
            events.emplace_back(b[1], b[2]);  // end
        }

        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        multiset<int> heights = {0};
        int prev = 0;
        vector<vector<int>> res;

        for (auto& [x, h] : events) {
            if (h < 0) heights.insert(-h);
            else heights.erase(heights.find(h));
            int curr = *heights.rbegin();
            if (curr != prev) {
                res.push_back({x, curr});
                prev = curr;
            }
        }

        return res;
    }
};
