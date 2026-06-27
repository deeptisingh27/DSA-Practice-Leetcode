class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //HASHING
        //TC = O(n) , SC = O(n)

        if (nums.size() == 0)
            return 0;

        unordered_set<int> s(nums.begin() , nums.end());
        
        int ans=0;

        for (int num : s){

            // num is the start of a sequence only if (num - 1) doesn't exist
            if(s.find(num-1) == s.end()){ 
                int curr = num;
                int count = 1;

                while (s.find(curr+1) != s.end()){
                    curr++;
                    count++;                    
                }

                ans = max(ans,count);
            }
        }

        return ans;
    }
};