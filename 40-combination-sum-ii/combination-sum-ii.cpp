class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int>& candidates, int target, vector<int>& v, int idx, vector<bool>& flag){
        if(target<0) return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(target>0 && !flag[i]){
                v.push_back(candidates[i]);
                flag[i] = true;
                combination(candidates, target-candidates[i], v, i+1, flag);
                flag[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<bool> flag(candidates.size(), false);
        combination(candidates, target, v, 0, flag);
        return ans;
    }
};