class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;

        while (i >= 0 || j >= 0) {
            int backspaces_s = 0, backspaces_t = 0;

            // Count backspaces for s
            while (i >= 0 && (s[i] == '#' || backspaces_s > 0)) {
                backspaces_s += (s[i] == '#') ? 1 : -1;
                i--;
            }

            // Count backspaces for t
            while (j >= 0 && (t[j] == '#' || backspaces_t > 0)) {
                backspaces_t += (t[j] == '#') ? 1 : -1;
                j--;
            }

            // Check if characters are equal (or both are empty after backspaces)
            if ((i >= 0 && j >= 0 && s[i] != t[j]) || (i < 0 && j >= 0) || (i >= 0 && j < 0)) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};
