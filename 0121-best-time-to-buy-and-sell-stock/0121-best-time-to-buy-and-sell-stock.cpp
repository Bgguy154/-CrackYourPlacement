class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int sum=0,i;
        // for(int j=1;j<prices.size();){
        //     i=prices[0];
        //     while(i<j){
        //     if(prices[j]-prices[i]>0){
        //         sum=max(sum,prices[j]-prices[i]);
        //         i++;
        //     }
        //         else{
        //             j++;
        //         }
        // }
        // }
        // return sum;
        // int x,i,j;
        // int sum=0;
        // stack <int>s;
        // for(int i=0;i<prices.size();i++){
        //     s.push(prices[i]);
        // }
        // x=s.top();
        // while(!s.empty()){
        //     i=s.top();
        //     s.pop();
        //     j=s.top();
        //     sum=max(sum,i,i-j);
        // }
        // if(sum==x) return 0;
        // return sum;
        
        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
};