class Solution {
 public:
  bool isNumber(string s) {
//       Let's analyze the string " -123.45e+6 " step-by-step.

//     Trim the String:
//         Before trimming: " -123.45e+6 "
//         After trimming: "-123.45e+6"

//     Initialize Flags:
//         seenNum = false
//         seenDot = false
//         seenE = false

//     Iterate through the String:
//         Character '-' at index 0:
//             Valid: Can appear at the start.
//             seenNum = false
//         Character '1' at index 1:
//             Digit found.
//             seenNum = true
//         Character '2' at index 2:
//             Digit found.
//             seenNum = true
//         Character '3' at index 3:
//             Digit found.
//             seenNum = true
//         Character '.' at index 4:
//             Dot found. Not seen before and not after an exponent.
//             seenDot = true
//         Character '4' at index 5:
//             Digit found.
//             seenNum = true
//         Character '5' at index 6:
//             Digit found.
//             seenNum = true
//         Character 'e' at index 7:
//             Exponent found. Not seen before and follows a digit.
//             seenE = true
//             seenNum = false (reset to ensure digits follow the exponent)
//         Character '+' at index 8:
//             Valid: Can appear after an exponent.
//             seenNum = false
//         Character '6' at index 9:
//             Digit found.
//             seenNum = true

//     Final Check:
//         At the end of the iteration, seenNum is true, indicating that a valid number was found.
      
    trim(s);
    if (s.empty())
      return false;

    bool seenNum = false;
    bool seenDot = false;
    bool seenE = false;

    for (int i = 0; i < s.length(); ++i) {
      switch (s[i]) {
        case '.':
          if (seenDot || seenE)
            return false;
          seenDot = true;
          break;
        case 'e':
        case 'E':
          if (seenE || !seenNum)
            return false;
          seenE = true;
          seenNum = false;
          break;
        case '+':
        case '-':
          if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
            return false;
          seenNum = false;
          break;
        default:
          if (!isdigit(s[i]))
            return false;
          seenNum = true;
      }
    }

    return seenNum;
  }

 private:
  void trim(string& s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
  }
};