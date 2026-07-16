class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //T.C. = O(n logn)
        //S.C. = O(n)

        int n = nums.size();

        int mx = 0;
        long long ans = 0;

        vector<int> prefixGcd; 
        
        for(int i=0 ; i<n ; i++){ 
            mx = max(mx, nums[i]);
            prefixGcd.push_back(__gcd(nums[i], mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n-1;

        while(i<j){
            ans += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }      

        return ans;
    }
};