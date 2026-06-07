class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int i = 1;
        int j = k;
        long long maxSum = sum;
        while(j<n){
            sum += nums[j];
            sum -= nums[i-1];    
            maxSum = max(maxSum, sum);
            i++;
            j++;
        }
        return (double)maxSum/k;
    }
};