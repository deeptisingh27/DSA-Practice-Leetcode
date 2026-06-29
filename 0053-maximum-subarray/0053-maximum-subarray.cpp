class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        /*

        //BRUTE FORCE 
        //T.C = O(n^2)

        int maxSum = INT_MIN;

        for(int start = 0 ; start<nums.size() ; start++){
            int currSum=0;

            for(int end = start ; end<nums.size() ; end++){
                currSum += nums[end];
                maxSum = max(maxSum,currSum);
            }
        }

        return maxSum;

        */


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