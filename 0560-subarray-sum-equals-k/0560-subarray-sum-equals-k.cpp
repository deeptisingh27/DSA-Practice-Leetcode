class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Time: O(n) , Space: O(n)
        //prefix sum + hashing

        unordered_map<int,int> mp; //<prefixSum , frequency>
        
        int currSum=0 , ans=0;

        for(int i:nums){
            currSum += i;

            //subarray starts from index 0
            if (currSum==k)
                ans += 1;

            //subarray starts after index 0
            //If there exists a prefix sum such that currSum - prefixSum = k
            if (mp.find(currSum-k) != mp.end())
                // Add all occurrences of (currSum - k)
                ans += mp[currSum-k];

            // Store/update the frequency of current prefix sum
            mp[currSum]++;
        }   

        return ans;


        //SLIDING WINDOW
        
    }
};