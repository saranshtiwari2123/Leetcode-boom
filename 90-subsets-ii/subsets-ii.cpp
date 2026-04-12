class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, vector<int> v, vector<vector<int>>& ans, int i, bool flag){
        if(i==nums.size()){
            ans.push_back(v);
            return ans;
        }
        if(i==nums.size()-1){
            if(flag)helper(nums,v,ans,i+1,true);
            v.push_back(nums[i]);
            helper(nums,v,ans,i+1,true);
        }
        else if(nums[i]==nums[i+1]){
            if(flag)helper(nums,v,ans,i+1,true);
            v.push_back(nums[i]);
            helper(nums,v,ans,i+1,false);
        }  
        else{
            if(flag)helper(nums,v,ans,i+1,true);
            v.push_back(nums[i]);
            helper(nums,v,ans,i+1,true);
        }
        return ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        return helper(nums,v,ans,0,true);
    }
};