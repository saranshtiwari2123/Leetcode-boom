class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, vector<int> v, vector<vector<int>>& ans, int i, int n){
        if(i==n){
            ans.push_back(v);
            return ans;
        }
        helper(nums,v,ans,i+1,n);
        v.push_back(nums[i]);
        helper(nums,v,ans,i+1,n);
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        return helper(nums,v,ans,0,n);
    }
};