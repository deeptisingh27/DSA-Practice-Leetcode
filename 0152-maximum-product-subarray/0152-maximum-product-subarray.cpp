class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        //brute force
        //T.C = O(n^2) , S.C = O(1)
        
        int n = nums.size();

        int ans = INT_MIN;
        
        for(int i=0 ; i<n ; i++){
            int prod = 1;

            for(int j=i ; j<n ; j++){
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }

        return ans;
        */


        //KADANE'S ALGORITHM
        // T.C = O(n) , S.C = O(1)

        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // Multiplying by a negative number flips max and min
            if (num < 0) {
                swap(currMax, currMin);
            }

            // Either start a new subarray at num, or extend previous product
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};