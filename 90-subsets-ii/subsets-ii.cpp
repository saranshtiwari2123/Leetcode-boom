class Solution {
public:
    vector<vector<int>> ans;
    vector<int>set;
    
    void solve(vector<int>&nums, int idx){
        if(idx==nums.size()){
            ans.push_back(set);
            return;
        }
        // Take
        set.push_back(nums[idx]);
        solve(nums,idx+1);
        set.pop_back();
        // Don't Take
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]){
            idx++;
        }
        solve(nums, idx + 1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};