class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int>ans;
        for(int ele:nums){
            mp[ele]++;
        }
        priority_queue<pi> pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        for(int i=0;i<k;i++){
            pair<int,int> t = pq.top();
            ans.push_back(t.second);
            pq.pop();
        }
        return ans;
    }
};