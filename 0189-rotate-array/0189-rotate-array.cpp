class Solution {
public:
    //reverse function using two-pointer technique
    void reverseArr(vector<int>& nums, int i, int j){

        while (i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        //T.C. = O(n) , S.C. = O(1)

        int n = nums.size();
        k %= n; //normalizing k

        /*
        //using built in reverse function

        reverse(nums.begin(), nums.end());       //Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); //Reverse first k elements
        reverse(nums.begin() + k, nums.end());   //Reverse remaining elements
        */

        reverseArr(nums, 0, n-1);
        reverseArr(nums, 0, k-1);
        reverseArr(nums, k, n-1);
    }
};