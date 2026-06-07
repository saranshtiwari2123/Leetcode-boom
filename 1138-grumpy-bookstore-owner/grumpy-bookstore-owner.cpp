class Solution {
public:
    int maxSatisfied(vector<int>& customer, vector<int>& grumpy, int minutes) {
        int n = customer.size();
        int sum = 0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                sum += customer[i];
            }
        }
        int i = 1;
        int j = minutes;
        int maxSum = sum;
        while(j<n){
            if(grumpy[i-1]==0 && grumpy[j]==0){
                i++;
                j++;
                continue;
            }
            else if(grumpy[i-1]==1 && grumpy[j]==0){
                sum -= customer[i-1];
            }
            else if(grumpy[i-1]==0 && grumpy[j]==1){
                sum += customer[j];
            }
            else{
                sum += customer[j]-customer[i-1];
            }
            maxSum = max(maxSum, sum);
            i++;
            j++;
        }
        int satisfied = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                satisfied += customer[i];
            }
        }
        return satisfied + maxSum;
    }
};