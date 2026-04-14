class Solution {
public:
    void permutation(vector<vector<int>>& ans, vector<int>& nums, vector<int>& v, vector<bool>& flag){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!flag[j]){
                v.push_back(nums[j]);
                flag[j] = true;
                permutation(ans, nums, v, flag);
                flag[j] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flag(n,false);
        vector<vector<int>> ans;
        vector<int> v;
        permutation(ans, nums, v, flag);
        return ans;
    }
};