class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        // Max./Min. Subarray Sum -> KADANE'S ALGORITHM

        int n = nums.size();

        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        //cumulative sum
        for(int i=1 ; i<n ; i++){ 
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        long long ans = LLONG_MIN;

        for(int start=0 ; start<k ; start++){ //(0 to k-1) because subarrays starts to repeat
            long long currSum = 0;

            int i=start;

            while(i<n && (i+k-1) < n){ //i and j must not be out of bounds
                int j = i+k-1;

                long long subSum = prefixSum[j] - ((i>0) ? prefixSum[i-1] : 0); //subarray sum

                currSum = max(subSum, currSum + subSum);

                ans = max(ans, currSum);

                i += k; //subarray length should be divisible by k
            }
        }

        return ans;
    }
};