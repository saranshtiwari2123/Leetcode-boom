class Solution {
public:
    void combination(vector<int>& candidates,int target,vector<int>ans,vector<vector<int>>& finalans,int idx){
        if(target==0){
            finalans.push_back(ans);
            return;
       }
       if(target<0) return;
       for(int i=idx;i<candidates.size();i++){
        ans.push_back(candidates[i]);
        combination(candidates,target-candidates[i],ans,finalans,i);
        ans.pop_back();
       }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>> finalans;
        combination(candidates,target,ans,finalans,0);
        return finalans;
    }
};