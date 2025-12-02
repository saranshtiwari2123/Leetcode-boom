class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        vector<int>ans;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto ele:m){
            pair<int,int> p;
            p.first = ele.second;
            p.second = ele.first;
            pq.push(p);
        }
        for(int i=0;i<k;i++){
            int x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};