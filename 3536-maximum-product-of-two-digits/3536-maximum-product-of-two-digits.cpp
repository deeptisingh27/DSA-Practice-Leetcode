class Solution {
public:
    int maxProduct(int n) {
        //T.C = O(log10n) , S.C = O(1)

        int ans = 0;
        int max_dig = 0; //keep track of max digit seen

        while(n > 0){
            int last_dig = n%10; 

            ans = max(ans, last_dig * max_dig);

            max_dig = max(max_dig, last_dig);

            n = n/10;
        }

        return ans;
    }
};