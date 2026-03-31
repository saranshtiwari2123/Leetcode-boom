class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }

        vector<int>ans(n,-1);
        int i=n-1;

        while(i>=0){
            while(!st.empty() && nums[i]>=st.top()) st.pop();

            if(!st.empty()) ans[i] = st.top();

            st.push(nums[i--]);
        }
        return ans;
    }
};