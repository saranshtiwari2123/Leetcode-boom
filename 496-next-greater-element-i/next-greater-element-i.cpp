class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = m-1;

        stack<int> st;
        vector<int> ans(m,-1);
        st.push(nums2[i--]);

        while(i>=0){
            while(!st.empty() && nums2[i]>st.top()) st.pop();

            if(!st.empty()) ans[i] = st.top();

            st.push(nums2[i--]);
        }

        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]] = ans[i];
        }

        for(int i=0;i<n;i++){
            if(mp.find(nums1[i])!=mp.end()) nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};