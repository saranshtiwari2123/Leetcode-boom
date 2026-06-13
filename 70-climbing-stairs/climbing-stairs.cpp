class Solution {
public:
    int dpclimb(int n, vector<int>& dp){
        if(n==1 || n==2) return n;
        if(dp[n-1]!=-1) return dp[n-1];
        dp[n-1] = dpclimb(n-1, dp) + dpclimb(n-2, dp);
        return dp[n-1];
    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return dpclimb(n, dp);

    }
};