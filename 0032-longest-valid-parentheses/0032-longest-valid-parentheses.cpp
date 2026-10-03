class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int open  = 0;
        int close = 0;

        int ans = 0;

        for(int i=0 ; i<n ; i++) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, open+close);
            }
            else if(close > open) { //going from left to right, if close is more it's no more valid
                open  = 0;
                close = 0;
            }
            // else open>close me move forward
        }

        open  = 0;
        close = 0;

        for(int i = n-1 ; i>=0 ; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open == close) {
                ans = max(ans, open+close);
            } 
            else if(open > close) { //going from right to left, if open is more, it's no more valid
                open  = 0;
                close = 0;
            }
            // else close>open me move forward
        }

        return ans;
    }
};