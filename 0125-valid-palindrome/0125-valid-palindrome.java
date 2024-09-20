public class Solution {
    
    public boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length() - 1;

        while (start <= end) {
            // Check if the character at start is alphanumeric
            while (start < s.length() && !Character.isLetterOrDigit(s.charAt(start))) {
                start++;
            }
            // Check if the character at end is alphanumeric
            while (end >= 0 && !Character.isLetterOrDigit(s.charAt(end))) {
                end--;
            }

            // Compare characters
            if (start <= end) {
                if (Character.toLowerCase(s.charAt(start)) != Character.toLowerCase(s.charAt(end))) {
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
    
    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        String testString = "A man, a plan, a canal: Panama"; // Example test
        boolean result = solution.isPalindrome(testString);
        System.out.println(result); // Output: true
    }
}
