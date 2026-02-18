class Solution {
public:

    int minc(vector<int>& cost, vector<int>& dp){
        int n = dp.size();
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=0;i<n-2;i++){
            dp[i+1] = min(dp[i+1],dp[i]+cost[i+1]);
            dp[i+2] = dp[i]+cost[i+2];  
        }
        return min(dp[n-2],dp[n-1]);

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        return minc(cost,dp);
    }
};