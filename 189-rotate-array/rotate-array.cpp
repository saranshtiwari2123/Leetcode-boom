class Solution {
public:
    void rotateByk(vector<int>& nums, int i, int j){
        while(i<=j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k %= n;
        rotateByk(nums, 0, n-1);
        rotateByk(nums, 0, k-1);
        rotateByk(nums, k, n-1);
    }
};