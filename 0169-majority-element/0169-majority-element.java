class Solution {
    public int majorityElement(int[] nums) {

        //Boyre-Moore Solution
        //T.C = O(n) , S.C = O(1)

        int m = -1;
        int count = 0;

        for (int j=0 ; j<nums.length ; j++){
            if (count == 0){
                m = nums[j]; // set the current candidate to nums[j]
                count = 1; // reset the counter to 1
            }

            // otherwise, increment the counter if nums[j] is a current candidate
            else if (m == nums[j]) {
                count++;
            }

            // otherwise, decrement the counter if nums[j] is a current candidate
            else {
                count--;
            }
        }

        return m;
    }
}