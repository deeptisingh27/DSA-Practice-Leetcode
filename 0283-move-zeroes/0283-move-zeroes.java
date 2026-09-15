class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;

        //Shift non-zero elements to the front
        for (int j=0 ; j<nums.length ; j++) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }

        //Fill remaining positions at the end with 0
        while (i < nums.length) {
            nums[i++] = 0;
        }
    }
}