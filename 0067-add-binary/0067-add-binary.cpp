class Solution {
public:
    string addBinary(string a, string b) {
        // Ensure both strings have equal length by padding with leading zeros
        int maxLength = max(a.length(), b.length());
        if (a.length() < maxLength) {
            a = string(maxLength - a.length(), '0') + a;
        }
        if (b.length() < maxLength) {
            b = string(maxLength - b.length(), '0') + b;
        }

        string u = "";
        int carry = 0;
        for (int i = maxLength - 1; i >= 0; i--) {
            if (a[i] == '0' && b[i] == '0') {
                u = char(carry + '0') + u;
                carry = 0;
            } else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')) {
                if (carry == 1) {
                    u = '0' + u;
                    carry = 1;
                } else {
                    u = '1' + u;
                    carry = 0;
                }
            } else {
                u = char(carry + '0') + u;
                carry = 1;
            }
        }
        if (carry == 1) {
            u = '1' + u;
        }
        return u;
    }
};
