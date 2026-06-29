class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //KADANE'S ALGORITHM
        //T.C. = O(n) , S.C. = O(1)

        int n = nums.size();

        int currSumMax = nums[0]; //current maximum subarray sum
        int maxSum = nums[0];  //maximum subarray sum

        int currSumMin = nums[0]; //current minimum subarray sum
        int minSum = nums[0]; //minimum subarray sum

        for(int i=1 ; i<n ; i++){ 
            //Kadane's Algo for max subarray sum
            currSumMax = max(nums[i], currSumMax + nums[i]);

            maxSum = max(maxSum, currSumMax);        

            //Kadane's Algo for min subarray sum
            currSumMin = min(nums[i], currSumMin + nums[i]);

            minSum = min(minSum, currSumMin);
        }

        return max(maxSum, abs(minSum));
    }
};