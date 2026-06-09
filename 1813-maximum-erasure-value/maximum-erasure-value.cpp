class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int sum = 0;
        int maxsum = 0;
        unordered_map<int, int> mp;

        while(j<nums.size()){
            mp[nums[j]]++;

            while((j-i+1)>mp.size()){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            maxsum = max(sum,maxsum);
            j++;
        }
        return maxsum;
    }
};