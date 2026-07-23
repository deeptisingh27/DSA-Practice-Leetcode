class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        //T.C = O(n) , S.C = O(1)

        long long ans = 0;
        int digits = 0;

        for(int num=1 ; num<=n ; num++){
            
            /*
            int digits = log2(num) + 1; //calculates the binary bit length of 'num'
            */

            //if 'num' is a power of 2, its binary representation needs 1 additional bit
            if((num & (num-1)) == 0){
                digits++;
            }
            
            //shift 'ans' left by 'digits' bits to make room for 'num' & add 'num'
            ans = ((ans << digits) % MOD + num) % MOD;
        }

        return ans;
    }
};