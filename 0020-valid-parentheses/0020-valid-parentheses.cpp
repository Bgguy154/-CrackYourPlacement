class Solution {
public:
    bool isValid(string s) {
         if(s.length()<=1){
            return false;
        }
        stack<char> stack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[' || s[i]=='{' || s[i]=='('){
                stack.push(s[i]);
            }
            else if(stack.empty()){
                return false;
            }
            else{
                if(s[i]==')'){
                    if(stack.top()!='('){
                        return false;
                    }
                }
                if(s[i]=='}'){
                    if(stack.top()!='{'){
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(stack.top()!='['){
                        return false;
                    }
                }
                stack.pop();
            }
        }
        if (stack.empty()){
            return true;
        }
        return false;
//         if(s.length()<=1)return false;
//         stack<char> st;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='['||s[i]=='{'||s[i]=='('){
//                 st.push(s[i]);
//             }
//             else if(s.empty()){
//                 return false;
//             }
//             else{
//                 if(s[i]=='}'){
//                     if(st.top()!='{'){
//                         return false;
//                     }
//                 }
//                  if(s[i]==')'){
//                     if(st.top()!='('){
//                         return false;
//                     }
//                 }
//                   if(s[i]==']'){
//                     if(st.top()!='['){
//                         return false;
//                     }
//                 }
//                 st.pop();
//             }
//         }
//         if(st.empty())return true;
        
//         return false;
    }
};