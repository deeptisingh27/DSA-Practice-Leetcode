class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int digit_sum = 0;
            
            while (val > 0) {
                digit_sum += val % 10;
                val /= 10;
            }
            
            if (digit_sum == i) {
                return i;
            }
        }
        return -1;
    }
};