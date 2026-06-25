class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        /*
        //APPROACH 1 TLE 
        //T.C. = O(n^3) 

        int ans=0;

        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i ; j<nums.size() ; j++){

                int count=0;

                // {i..j}
                for(int k=i ; k<=j ; k++){
                    if(nums[k] == target) 
                        count++;
                }

                if(count > (j-i+1) / 2) 
                    ans++;
            }
        }

        return ans;
        */


        //APPROACH 2 
        //T.C. = O(n^2) 

        int ans=0;

        for(int i=0 ; i<nums.size() ; i++){
            int count=0;
            
            for(int j=i ; j<nums.size() ; j++){

                count += (nums[j] == target ? 1 : 0);

                if(count > (j-i+1) / 2) 
                    ans++;
            }
        }

        return ans;

    }
};