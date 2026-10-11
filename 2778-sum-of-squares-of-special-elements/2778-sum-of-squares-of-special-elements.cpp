class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        //T.C = O(n) , S.C = O(1)

        int n = nums.size();
        int sum=0;

        for(int i=1 ; i<=n ; i++){
            if(n%i == 0){
                int x = nums[i-1]; //access element using 0-based indexing
                sum += x*x;
            }
        }

        return sum;
    }
};