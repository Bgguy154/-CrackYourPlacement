class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces and reduce multiple spaces to single spaces
        stringstream ss(s);
        string word;
        vector<string> words;
        
        // Split the string into words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse the order of the words
        reverse(words.begin(), words.end());
        
        // Join the words back into a single string with a single space separating them
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};
