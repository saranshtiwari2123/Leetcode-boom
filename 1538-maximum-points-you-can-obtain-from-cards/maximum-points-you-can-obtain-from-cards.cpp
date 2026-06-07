class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = n-k;
        int sum = 0;
        for(int i=0;i<s;i++){
            sum += cardPoints[i];
        }
        int i=1;
        int j=s;
        int minSum = sum;
        while(j<n){
            sum += cardPoints[j];
            sum -= cardPoints[i-1];
            minSum = min(minSum, sum);
            i++;
            j++;
        }
        sum = 0;
        for(auto ele:cardPoints){
            sum += ele;
        }
        return sum-minSum;

        

    }
};