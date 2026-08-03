class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long temp = x;
        long long rev = 0;
        while(temp>0){
            long long d = temp%10;
            temp = temp/10;
            rev = rev*10 + d;
        }
        if(x==rev){
            return true;
        }
        else return false;

    }
};