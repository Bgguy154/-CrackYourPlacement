class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // int n=cardPoints.size();
        // if(k==0)return 0;
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     for(int j=n-1;j>0;j--){
        //         while(k){
        //             sum+=max(cardPoints[i],cardPoints[j]);
        //         }
        //     }
        // }
        //     return sum%2147483647;
         int n = cardPoints.size();

        int leftSum = 0;

        for (int i = 0; i < k;

             i++) {  // calculate sum where all cards on the left side

            leftSum += cardPoints[i];

        }

        int rightSum = 0;

        int rightIndex = n;  // pointer for the right cards

        int ans = leftSum;

        for (int leftIndex = k - 1; leftIndex >= 0;

             leftIndex--) {                    // pointer for the left cards

            leftSum -= cardPoints[leftIndex];  // transition between choices

            rightIndex--;

            rightSum += cardPoints[rightIndex];

            ans = max(ans, leftSum + rightSum);

        }

        return ans;
    }
};