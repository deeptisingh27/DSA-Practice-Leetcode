class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        //T.C = O(n) , S.C = O(1)
        int n = nums.size();

        int ans = 0;
        bool allZero = true;

        for(int x : nums){
            ans = (ans ^ x);

            if(x != 0){ //atleast one element is not zero
                allZero = false;
            }
        }

        //if all elements are 0, no non-zero XOR exists
        if(allZero) return 0;

        //if total XOR != 0, take all n elements
        //otherwise remove any non-zero element leaves a non-zero XOR of size n-1
        return (ans == 0) ? n-1 : n;
    }
};