class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int minlen = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                int len = j-i+1;
                minlen = min(minlen,len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};