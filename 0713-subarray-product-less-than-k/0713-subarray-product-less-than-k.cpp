class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        //T.C = O(n^2)

        int n = nums.size();
        int count = 0;

        for(int i=0 ; i<n ; i++){
            long long prod = 1;

            for(int j=i ; j<n ; j++){
                prod *= nums[j];

                if (prod < k)
                    count++;
                else
                    break;
            }
        }

        return count;
        */


        //SLIDING WINDOW
        //T.C = O(n)
        
        if (k <= 1) return 0;

        int count = 0;
        int prod = 1;
        int i = 0;

        for (int j=0 ; j<nums.size() ; j++) {
            prod *= nums[j];

            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += j - i + 1;
        }

        return count;
    }
};