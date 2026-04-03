class Solution {
public:
    int prio(char ch){
        if(ch=='+' || ch=='-') return 1;
        else return 2;
    }
    int solve(int v1, int v2, char ch){
        if(ch=='+') return v1+v2;
        else if(ch=='-') return v1-v2;
        else if(ch=='*') return v1*v2;
        else return v1/v2;
    }
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

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            string s = tokens[i];
            if(isInteger(s)) st.push(stoi(s));
            else{
                char ch = s[0];
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                st.push(solve(v1,v2,ch));
            }
        }
        return st.top();
    }
};