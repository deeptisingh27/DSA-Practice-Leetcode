class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // max./min. subarray -> KADANE'S ALGORITHM 
        // T.C = O(n) , S.C = O(n)

        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1 ; i<nums.size() ; i++){

            currSum = max(nums[i], currSum + nums[i]);

            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};