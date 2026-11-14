class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        //BRUTE FORCE: gives TLE
        //T.C = O(n^2) , S.C = O(1)

        /*
        int n = nums.size();
        int l = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int sum = 0;

            for(int j=i; j<n ; j++){
                sum += nums[j];

                if(sum >= target){
                    l = min(l, j-i+1);
                    break;
                }
            }
        }

        return (l == INT_MAX) ? 0 : l;
        */


        //contiguous subarray -> SLIDING WINDOW
        //T.C = O(n) , S.C = O(1)

        /*
        int n = nums.size();
        int l = INT_MAX; //min. length of subarray
        int i = 0, j = 0;
        int sum = 0;

        for(j=0 ; j<n ; j++){
            sum += nums[j];

            while(sum >= target){
                l = min(l, j-i+1);

                sum -= nums[i];
                i++;
            }
        }

        return (l == INT_MAX) ? 0 : l;
        */


        //Prefix Sum + Binary Search
        //T.C = O(n logn) , S.C = O(n)
        //array ke saare numbers positive hai, positive numbers ko add krte jaate hain, toh sum hamesha badhta hi rehta hai (strictly increasing), isiliye hum Binary Search laga sakte hai

        int n = nums.size();
        int min_len = INT_MAX;
        
        // Step 1: Prefix sum array banana
        vector<int> prefix(n+1, 0);
        for (int i=0 ; i<n ; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        // Step 2: Har starting index 'i' ke liye sahi ending index 'j' dhoondhenge
        for (int i=0 ; i<n ; i++) {
            int required_sum = target + prefix[i];

            // Step 3: Khud ka Binary Search (bina lower_bound ke)
            int low = i + 1;
            int high = n;
            int j = -1; // Yahan sabse chhota valid index store hoga

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (prefix[mid] >= required_sum) {
                    j = mid; //Ek valid answer mil gya, pr humein min. length chahiye
                    high = mid-1; //isliye left side me or chhota j dhoondhne jayenge
                } 
                else {
                    low = mid + 1; //sum abhi chhota hai, right side mein bada sum dhoondho
                }
            }

            // Agar valid 'j' mil gaya toh minimum length update karo
            if (j != -1) {
                min_len = min(min_len, j - i);
            }
        }

        // Agar koi subarray nahi mila toh 0, warna min_len return karo
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};