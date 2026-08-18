class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        
        //case 1: k==n
        //only one subarray possible, select max element in the whole array
        if (k == n) {
            int ans = -1;

            for (int x : nums) {
                ans = max(ans, x);
            }

            return ans;
        }

        //case 2: k==1
        //every index is one subarray, find largest element which appears once
        if(k == 1){
            int ans = -1;

            for (auto& [val, count] : freq) {
                if (count == 1) {
                    ans = max(ans, val);
                }
            }

            return ans;
        }

        //case 3: 1 < k < n
        //only the first and last element are going to be the ones which will appear only in one subarray
        
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};