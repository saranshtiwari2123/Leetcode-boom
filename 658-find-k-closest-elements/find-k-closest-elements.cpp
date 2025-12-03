class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue< pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pair<int,int> p;
            p.first = abs(arr[i]-x);
            p.second = arr[i];
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};