class Solution {
public:
    int smallestNumber(int n, int t) {
        //T.C = O(1) = S.C

        for(int i=n ; i<=100 ; i++){
            int prod = 1;
            int temp = i;

            while(temp>0){
                int dig = temp%10;
                prod *= dig;
                temp /= 10;
            }

            if(prod % t == 0)
                return i;
        }

        return n;
    }
};