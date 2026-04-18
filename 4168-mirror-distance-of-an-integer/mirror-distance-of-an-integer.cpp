class Solution {
public:
    int reverse(int n){
        int d = 0;
        while(n>0){
            d *= 10;
            d += n%10;
            n /= 10;
        }
        return d;

    }
    int mirrorDistance(int n) {
        int r = reverse(n);
        return abs(n-r);
    }
};