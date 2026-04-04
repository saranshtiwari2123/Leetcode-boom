class Solution {
public:
    int prio(char ch){
        if(ch=='+'||ch=='-') return 1;
        else return 2;
    }

    int solve(int v1, int v2, char ch){
        if(ch=='+') return v1+v2;
        else if(ch=='-') return v1-v2;
        else if(ch=='*') return v1*v2;
        else return v1/v2;
    }

    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        stack<char> op;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch==' ') continue;
            if(isdigit(ch)){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
            st.push(num);
            i--;
}
            else{                
                while(!op.empty() && prio(ch)<=prio(op.top())){
                    int v2 = st.top();
                    st.pop();
                    int v1 = st.top();
                    st.pop();
                    st.push(solve(v1,v2,op.top()));
                    op.pop();
                }
                op.push(ch);
            }
        }
        while(!op.empty()){
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(solve(v1,v2,op.top()));
            op.pop();
        }
        return st.top();

    }
};