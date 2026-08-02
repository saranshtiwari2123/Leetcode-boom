class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        return helper(n, sums);
    }

private:
    vector<int> helper(int n, vector<int>& sums) {
        if (n == 0) return {};

        int x = sums[1] - sums[0];

        multiset<int> st(sums.begin(), sums.end());
        vector<int> withoutX, withX;

        while (!st.empty()) {
            int a = *st.begin();
            st.erase(st.begin());

            withoutX.push_back(a);

            auto it = st.find(a + x);
            withX.push_back(a + x);
            st.erase(it);
        }

        // If 0 belongs to the "withoutX" group,
        // then x is a positive element.
        if (find(withoutX.begin(), withoutX.end(), 0) != withoutX.end()) {
            vector<int> ans = helper(n - 1, withoutX);
            ans.push_back(x);
            return ans;
        }

        // Otherwise x is actually negative.
        vector<int> ans = helper(n - 1, withX);
        ans.push_back(-x);
        return ans;
    }
};