class Solution {
public:
    int atmostK(vector<int>& nums, int goal){
        int i=0;
        int j=0;
        int count = 0;
        int ans = 0;
        while(j<nums.size()){
            if(nums[j]==1) count++;
            while(count>goal){
                if(nums[i]==1) count--;
                i++;
            }
            ans += j-i+1;
            j++;
            
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return atmostK(nums, goal);
        return atmostK(nums, goal)-atmostK(nums, goal-1);
    }
};