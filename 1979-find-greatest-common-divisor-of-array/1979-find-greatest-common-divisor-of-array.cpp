class Solution {
public:
    int gcd(int a, int b){ //O(log(max(nums)))
        while(b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        return a;
    }

    int findGCD(vector<int>& nums) {
        //Euclidean Algorithm
        //T.C = O(n) , S.C = O(1)

        int a = INT_MIN; //max element of array
        int b = INT_MAX; //min element of array

        for(int i=0 ; i<nums.size() ; i++){ //O(n)
            a = max(a, nums[i]);
            b = min(b, nums[i]);
        }

        return gcd(a, b);
    }
};