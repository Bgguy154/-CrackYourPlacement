class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // If needle is empty, return 0
        
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == m) return i; // If all characters in needle match
        }
        return -1; // Needle not found
    }
};
