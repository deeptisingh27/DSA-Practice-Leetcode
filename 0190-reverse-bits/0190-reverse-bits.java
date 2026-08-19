class Solution {
    public int reverseBits(int n) {

        int ans = 0;

        for (int i = 0; i < 32; i++) {
            //shift ans left to make room for the next bit and extract the last bit of n and add it to ans
            ans = (ans << 1) | (n & 1);

            // Logical shift right to process the next bit
            n >>>= 1;
        }

        return ans;
    }
}