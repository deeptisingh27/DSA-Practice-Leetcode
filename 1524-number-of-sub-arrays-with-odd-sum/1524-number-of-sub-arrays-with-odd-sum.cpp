class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        //T.C = O(n) , S.C = O(1)
        
        int n = arr.size();
        int prefixSum = 0;
        int count = 0;

        // evenCount starts at 1 to account for a prefix sum of 0 (empty subarray)
        int evenCount = 1; 
        int oddCount = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 != 0) {
                // Current prefix sum is odd: pair with all previous even prefix sums
                count = (count + evenCount) % MOD;
                oddCount++;
            } else {
                // Current prefix sum is even: pair with all previous odd prefix sums
                count = (count + oddCount) % MOD;
                evenCount++;
            }
        }

        return count;
    }
};