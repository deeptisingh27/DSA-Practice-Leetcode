class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //T.C = O(n^2) , S.C = O(1)

        int n = nums.size();

        for(int i=0 ; i<n ; i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;

            // maxi = *max_element(nums.begin(), nums.begin() + i + 1);
            // mini = *min_element(nums.begin() + i, nums.end());

            
            for(int j=0 ; j<=i ; j++){
                maxi = max(maxi, nums[j]);
            }

            for(int j=i ; j<=n-1 ; j++){
                mini = min(mini, nums[j]);
            }

            if(maxi - mini <= k){
                return i;
            }
        }

        return -1;
    }
};