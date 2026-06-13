class Solution {
public:
    int findComplement(int n) {
        long long temp = 0;
        long long k = (long long)n;
        while(n>0){
            temp = n;
            n = (n&(n-1));
        }
        temp = temp<<1;
        return ((temp-1)^k);
    }
};