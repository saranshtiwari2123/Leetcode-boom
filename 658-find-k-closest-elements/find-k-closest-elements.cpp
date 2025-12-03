class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(arr[i]>=x){
                idx = i;
                break;
            }
        }
        if(idx==-1) idx = n;
        int j = idx;
        int i = idx-1;
        while(i>=0 && j<n && k>0){
            if(abs(arr[i]-x)<=abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
                k--;
            }
            else{
                ans.push_back(arr[j]);
                j++;
                k--;
            }
        }

        if(i<0){
            while(k>0){
                ans.push_back(arr[j++]);
                k--;
            }
        }
        if(j>=n){
            while(k>0){
                ans.push_back(arr[i--]);
                k--;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};