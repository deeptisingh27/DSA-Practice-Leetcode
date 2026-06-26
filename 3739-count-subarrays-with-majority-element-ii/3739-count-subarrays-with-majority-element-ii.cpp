class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        //T.C. = O(n)

        unordered_map<int, int> mp; //{cumulative sum -> count}
        mp[0] = 1;

        int cumSum=0; //cumulative sum

        long long validLeftPoints = 0;
        long long ans=0;

        for(int i=0 ; i<nums.size() ; i++){

            if(nums[i] == target){
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            }

            else{
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum] += 1;
            ans += validLeftPoints;
        }

        return ans;
    }
};