class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int>& v, int n, int k, int idx){
        if(n<0) return;
        if(n==0){
            if(v.size()==k) ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(n>0){
                v.push_back(i);
                if(n>-1)combination(v, n-i, k, i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        combination(v, n, k, 1);
        return ans;
    }
};