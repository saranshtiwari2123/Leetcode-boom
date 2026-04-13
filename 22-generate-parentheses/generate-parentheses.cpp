class Solution {
public:

    void genAi(vector<string>& ans, string s, int op, int cl, int n){
        if(cl==n){
            ans.push_back(s);
        }
        if(op<n) genAi(ans,s+"(",op+1,cl,n);
        if(cl<op) genAi(ans,s+")",op,cl+1,n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        genAi(ans,"",0,0,n);
        return ans;
    }
};