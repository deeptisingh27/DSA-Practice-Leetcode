class Solution {
public:
    int maxProduct(vector<int>& nums) {

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
    }
};