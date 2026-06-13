class Solution {
public:

    int minc(vector<int>& cost, vector<int>& dp, int i){
        if(i==0 || i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i] + min(minc(cost, dp, i-1), minc(cost, dp, i-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(minc(cost, dp, n-1), minc(cost, dp, n-2));
    }
};