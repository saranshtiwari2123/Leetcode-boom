class Solution {
public:
    int totalFruit(vector<int>& fruits) {        
        int n = fruits.size();
        if(n==1) return 1;
        int i = 0;
        int j = 1;
        
        int k = j;
        int maxcount = 0;
        while(k<n){
            while(j<n && fruits[i]==fruits[j]) j++;
            if((fruits[k]==fruits[i]) || (fruits[k]==fruits[j])) k++;
            else{
                maxcount = max(maxcount, (k-i));
                i = j;
                j++;
                
            }
        }
        maxcount = max(maxcount, (k-i));
        return maxcount;
    }
};