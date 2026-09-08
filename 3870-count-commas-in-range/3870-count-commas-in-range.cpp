class Solution {
public:
    int countCommas(int n) {

        //O(log n) Solution

        if(n < 4) return 0;

        long long commas = 0;

        //each threshold represents where comma is introduced: 1,000 (1st comma), 1,000,000 (2nd comma), etc.
        long long threshold = 1000;

        while(n >= threshold){
            commas += n - threshold + 1;
            threshold *= 1000; //move to the next comma (1,000 -> 1,000,000)
        }       

        return commas;
    }
};