class Solution {
public:
    int maxProduct(int n) {
        /*
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
        */


        //usings orting
        //T.C = O(n log n) , S.C = O(n)

        string s = to_string(n);

        sort(s.begin(), s.end());

        int len = s.size();

        //convert the last two char digits back to int values
        int max1 = s[len - 1] - '0';
        int max2 = s[len - 2] - '0';

        return max1 * max2;
    }
};