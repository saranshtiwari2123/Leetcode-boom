class Solution {
public:
    int roberry(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2]+dp[0];
        for(int i=3;i<n;i++){
            dp[i] = max((dp[i-2]+nums[i]),dp[i-3]+nums[i]);
        }
        return max(dp[n-1],dp[n-2]);
    }
    int rob(vector<int>& num) {
        int n = num.size();
        if(n==1) return num[0];
        if(n==2) return max(num[0],num[1]);
        vector<int> nums1(n-1);
        vector<int> nums2(n-1);
        for(int i=0;i<n-1;i++){
            nums1[i] = num[i];
        }
        for(int i=1;i<n;i++){
            nums2[i-1] = num[i];
        }
        int x = roberry(nums1);
        int y = roberry(nums2);
        return max(x,y);
    }
};