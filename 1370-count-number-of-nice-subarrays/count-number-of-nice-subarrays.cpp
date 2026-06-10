class Solution {
public:
    int atmostKOdd(vector<int>& nums, int k){
        int i=0;
        int j=0;
        int count = 0;
        int odd = 0;
        while(j<nums.size()){
            if(nums[j]%2==1) odd++;
            while(odd>k){
                if(nums[i]%2==1) odd--;
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostKOdd(nums, k)-atmostKOdd(nums, k-1);
    }
};