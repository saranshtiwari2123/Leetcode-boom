class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int>& v, vector<bool>& flag, int n, int k, int idx){
        if(n<0) return;
        if(n==0){
            if(v.size()==k) ans.push_back(v);
            return;
        }
        for(int i=idx;i<=9;i++){
            // if(i>idx)
            if(!flag[i]){
                v.push_back(i);
                flag[i] = true;
                n -= i;
                if(n>-1)combination(v, flag, n, k, i+1);
                n += i;
                flag[i] = false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<bool> flag(10, false);
        vector<int> v;
        combination(v, flag, n, k, 1);
        return ans;
    }
};