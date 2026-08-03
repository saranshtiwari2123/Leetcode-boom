class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, vector<int>& v, int idx){
        if(target<0) return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(target>0){
                v.push_back(candidates[i]);
                target -= candidates[i];

                solve(candidates, target, v, i);

                target += candidates[i];
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(candidates, target, v, 0);
        return ans;
    }
};