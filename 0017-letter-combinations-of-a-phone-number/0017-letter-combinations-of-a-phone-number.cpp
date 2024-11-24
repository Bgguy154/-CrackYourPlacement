class Solution {
public:
   void solve(vector<string> &ans, string output, int i, string digits, string mapping[]){
        //base case
        if(i >= digits.length()){
            ans.push_back(output);
            return ;
        }

        int number = digits[i] - '0';                   //2 from "23"
        string value = mapping[number];                 //"abc"

        for(int k = 0; k < value.length(); k++){
            output.push_back(value[k]);                 //pushing a from "abc"
            solve(ans, output, i+1, digits, mapping);   //recursive call for the next number from digits string
            output.pop_back();                          //to remove the "a","b","c" through backtracking
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length() == 0){
            return ans;
        }

        string output;
        int i = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(ans, output, i, digits, mapping);
        return ans;

    }
};