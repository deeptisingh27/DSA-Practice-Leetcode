class Solution {
public:
    const int MOD = 1e9 + 7;

    int concatenatedBinary(int n) {
        //T.C = O(n) , S.C = O(1)

        long long ans = 0;

        for(int num=1 ; num<=n ; num++){
            //calculates the binary bit length of 'num'
            int digits = log2(num) + 1;
            
            //shift 'ans' left by 'digits' bits to make room for 'num' & add 'num'
            ans = ((ans << digits) % MOD + num) % MOD;
        }

        return ans;
    }
};