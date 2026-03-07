class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i=0;i<n-1;i++){
            int k = i+1;
            for(int j=0;j<nums[i];j++){
                if(dp[n-1]==true) return true;
                if(dp[i]==false) return false;
                dp[k++] = true;
            }
        }
        if(dp[n-1]==true) return true;
        return false;
    }
};