class Solution {
public:
    int firstUniqChar(string s) {
        // int n=s.length();
        // int b=-1;
        // for(int i=1;i<n;i++){
        //     if(s[i]!=s[i-1]){
        //         b=i-1;
        //         break;
        //     }
        // }
        // return b;
        
         int count[26]={0};
        for(int i =0;i< s.size(); i++)
        {
            count[s[i]-'a']++;

        }
        for(int i =0;i< s.size(); i++)
        {
            if(count[s[i]-'a']==1)
            return i;
        }
        return -1;
    }
};