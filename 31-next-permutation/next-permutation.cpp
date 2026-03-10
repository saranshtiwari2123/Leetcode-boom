class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1, j = n-1;
        bool flag = false;
        while(i>0){
            if(nums[i]>nums[i-1]){
                i--;
                flag = true;
                break;
            }
            i--;    
        }
        if(flag){
            reverse(nums.begin()+i+1, nums.end());
            int m;
            for(int k=i+1;k<n;k++){
                if(nums[k]>nums[i]){
                    m = k;
                    break;
                }
            }
            int temp = nums[i];
            nums[i] = nums[m];
            nums[m] = temp;
        }
        else reverse(nums.begin(), nums.end());
    }
};