// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int n=1;
//         int h=s.length()-1;
//         while(s[h]!=' ' || h!=0){
//             n++;
//             h--;
//         }
//         return n;
//     }
// };

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;
        int h = s.length() - 1;

        // Skip trailing spaces if any
        while (h >= 0 && s[h] == ' ') {
            h--;
        }

        // Now count the length of the last word
        while (h >= 0 && s[h] != ' ') {
            n++;
            h--;
        }

        return n;
    }
};
