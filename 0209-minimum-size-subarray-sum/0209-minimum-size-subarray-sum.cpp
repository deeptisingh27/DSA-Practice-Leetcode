class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        /*

        //BRUTE FORCE: gives TLE
        //T.C = O(n^2) , S.C = O(1)

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

        int n = nums.size();
        int l = INT_MAX; //min. length of subarray
        int i = 0, j = 0;
        int sum = 0;

        while(j<n){
            sum += nums[j];

            while(sum >= target){
                l = min(l, j-i+1);

                sum -= nums[i];
                i++;
            }

            j++;
        }

        return (l == INT_MAX) ? 0 : l;;
    }
};