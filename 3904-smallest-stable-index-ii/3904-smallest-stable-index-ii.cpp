class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        //T.C = O(n) , S.C = O(n)

        int n = nums.size();

        vector<int> minFromIdx(n);
        int mini = INT_MAX;

        for (int i=n-1 ; i>=0 ; i--) {
            mini = min(mini, nums[i]);
            minFromIdx[i] = mini;
        }

        int maxi = INT_MIN;

        for (int i=0 ; i<n ; i++){
            maxi = max(maxi, nums[i]);            
            mini = minFromIdx[i];

            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};