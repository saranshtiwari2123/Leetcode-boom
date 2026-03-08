class Solution {
public:
    int trio(int n, vector<int>& dp){
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n] = trio(n-1,dp) + trio(n-2,dp) + trio(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return trio(n, dp);
    }
};