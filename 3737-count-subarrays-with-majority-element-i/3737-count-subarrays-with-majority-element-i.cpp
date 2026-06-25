class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        /*
        //APPROACH 1 : gives TLE 
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

                int len = j - i + 1;

                if(count > len / 2) 
                    ans++;
            }
        }

        return ans;
        */


        /*
        //APPROACH 2 
        //T.C. = O(n^2) 

        int ans=0;

        for(int i=0 ; i<nums.size() ; i++){
            int count=0;
            
            for(int j=i ; j<nums.size() ; j++){

                count += (nums[j] == target ? 1 : 0);

                int len = j - i + 1;
                if(count > len / 2) 
                    ans++;
            }
        }

        return ans;
        */


        //APPROACH 3
        //T.C. = O(n^2)
        int ans=0;

        for(int i=0 ; i<nums.size() ; i++){
            int count=0;
            
            for(int j=i ; j<nums.size() ; j++){

                count += (nums[j] == target ? 1 : -1);

                if(count > 0) //{i..j} has target as majority element
                    ans++;
            }
        }

        return ans;
        

    }
};