class Solution {
public:

bool isInteger(string s) {
    if (s.empty()) return false;

    int i = 0;

    if (s[0] == '-' || s[0] == '+') {
        if (s.size() == 1) return false;
        i = 1;
    }

    for (; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }

    return true;
}
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            string s = operations[i];
            if(isInteger(s)) st.push(stoi(s));
            else if(s[0]=='+'){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(s[0]=='D'){
                st.push(2*(st.top()));
            }
            else st.pop();
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};