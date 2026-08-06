class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& v, vector<bool>& flag){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && !flag[i-1]) continue;
            if(!flag[i]){
                v.push_back(nums[i]);
                flag[i] = true;

                solve(nums, v, flag);

                flag[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<bool> flag(nums.size(), false);
        solve(nums, v, flag);
        return ans;
    }
};