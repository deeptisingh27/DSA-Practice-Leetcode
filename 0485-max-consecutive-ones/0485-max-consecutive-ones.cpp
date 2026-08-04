class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int currCount = 0; //current no. of consecutive 1s
        int ans = 0; //maximum no. of consecutive 1's

        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                currCount++;
                ans = max(ans, currCount);
            }

            else{
                currCount = 0;
            }
        }

        return ans;
    }
};