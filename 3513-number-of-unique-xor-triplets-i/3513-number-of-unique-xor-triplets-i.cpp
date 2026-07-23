class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        //T.C = O(log n) , S.C = O(1)
        
        int n = nums.size();

        //base case
        if(n == 1 || n == 2){
            return n;
        }

        int ans = 1; //2^0
        while(ans <= n){
            ans *= 2; //ans = (ans << 1);
        }

        return ans;
    }
};