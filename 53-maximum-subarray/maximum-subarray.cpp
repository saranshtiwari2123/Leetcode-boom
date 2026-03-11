class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int v1 = nums[0];
        int v2 = nums[0];
        int ans = nums[0];
        int best = nums[0];
        for(int i=1;i<n;i++){
            v1 = ans+nums[i];
            v2 = nums[i];
            ans = max(v1,v2);
            best = max(best,ans);
        }
        return best;
    }
};