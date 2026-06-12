class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        if(s1.size()>s2.size()) return {};
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<int> ans;

        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }

        for(int i=0;i<s1.size();i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2) ans.push_back(0);
        int i=0;
        for(int j = s1.size();j<s2.size();j++){
            freq2[s2[j]-'a']++;
            freq2[s2[i]-'a']--;
            i++;
            if(freq1==freq2) ans.push_back(i);
            
        }
        return ans;
    }
};