class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int i = 0;
        int j = 0;

        for(j=0 ; j<n ; j++){
            if (nums[j] == 0){
                k--;
            }

            // Shrink the window from the left if zeroes exceed k
            while (k<0) {

                //if the element leaving the window is zero, restore allowance to k
                if (nums[i] == 0) {
                    k++;
                }
                
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};