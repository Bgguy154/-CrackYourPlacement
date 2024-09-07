class Solution {
public:
    string largestOddNumber(string num) {
        // int n=num.size();
        // int a[n];
        // for(int i=0;i<n;i++){
        //     a[i]=stoi(num[i]);
        // }
        // int o=1;
        // for(int m=0;m<n;m++){
        //     if(a[m]%2!=0){
        //     o=max(o,a[m]);
        //     }
        // }
        // return o;
        
          for(int i = num.size()-1; i >= 0; i--)
        {
            // char to ascii conversion by subtraction 48 (ASCII of 0)
            if((int)(num[i] - 48) % 2 != 0)
            {
                // here return i+1 as the last index is excluded while using the substr function
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};