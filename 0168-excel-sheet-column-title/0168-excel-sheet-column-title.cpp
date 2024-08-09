class Solution {
 public:
  string convertToTitle(int n) {
    return n == 0 ? ""
                  : convertToTitle((n - 1) / 26) + (char)('A' + ((n - 1) % 26));
  }
//     This C++ code defines a method called convertToTitle in the Solution class, which converts a given integer n into its corresponding Excel column title.
// Explanation

// Excel columns are labeled in a way similar to a base-26 numbering system, but with letters instead of digits and no zero. For example:

//     Column 1 is labeled "A",
//     Column 2 is labeled "B",
//     Column 26 is labeled "Z",
//     Column 27 is labeled "AA",
//     Column 28 is labeled "AB",
//     and so on.

// How the Code Works

// The method is recursive. Let's break down the code:

// cpp

// string convertToTitle(int n) {
//     return n == 0 ? ""
//                   : convertToTitle((n - 1) / 26) + (char)('A' + ((n - 1) % 26));
// }

//     Base Case (n == 0 ? ""):
//         If n is 0, return an empty string because there is no corresponding column title.

//     Recursive Case:
//         First Part (convertToTitle((n - 1) / 26)):
//             (n - 1) / 26 adjusts n by reducing it to handle the base-26 nature. This recursive call moves to the next "digit" in the column title.
//         Second Part ((char)('A' + ((n - 1) % 26))):
//             (n - 1) % 26 gives the remainder when n-1 is divided by 26, which determines the current character. Adding 'A' converts this to the appropriate character between 'A' and 'Z'.

//     Combining the Parts:
//         The recursive part builds the title from left to right.

// Example: convertToTitle(28)

// Let's trace the execution for n = 28:

//     First Call: convertToTitle(28)
//         Calculate convertToTitle((28 - 1) / 26) = convertToTitle(1)
//         Calculate (char)('A' + ((28 - 1) % 26)) = (char)('A' + (27 % 26)) = (char)('A' + 1) = 'B'
//         Combine results: "A" + "B" = "AB"

//     Second Call: convertToTitle(1)
//         Calculate convertToTitle((1 - 1) / 26) = convertToTitle(0)
//         Calculate (char)('A' + ((1 - 1) % 26)) = (char)('A' + 0) = 'A'
//         Combine results: "" + "A" = "A"

// The final result is "AB".
// Example: convertToTitle(701)

// Let's trace the execution for n = 701:

//     First Call: convertToTitle(701)
//         Calculate convertToTitle((701 - 1) / 26) = convertToTitle(26)
//         Calculate (char)('A' + ((701 - 1) % 26)) = (char)('A' + (700 % 26)) = (char)('A' + 24) = 'Z'
//         Combine results: "A" + "Z" = "ZZ"

//     Second Call: convertToTitle(26)
//         Calculate convertToTitle((26 - 1) / 26) = convertToTitle(0)
//         Calculate (char)('A' + ((26 - 1) % 26)) = (char)('A' + 25) = 'Z'
//         Combine results: "" + "Z" = "Z"

// The final result is "ZZ".

// Thus, convertToTitle(701) returns "ZZ".
};