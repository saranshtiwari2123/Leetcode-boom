class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<bool>& flag, vector<int>& v){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!flag[i]){
                v.push_back(nums[i]);
                flag[i] = true;
                solve(nums, flag, v);
                flag[i] = false;
                v.pop_back();
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<bool> flag(nums.size(), false);
        solve(nums, flag, v);
        return ans;
    }
};