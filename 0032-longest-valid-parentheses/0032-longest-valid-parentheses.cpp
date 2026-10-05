class Solution {
public:
    int longestValidParentheses(string s) {
        //Approach-1 (Using 2 pass)
        //T.C = O(n) , S.C = O(1)

        /*
        int n = s.length();

        int open  = 0;
        int close = 0;

        int ans = 0;

        // Left to right
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

        // Right to left
        int open  = 0;
        int close = 0;
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
        */


        //Approach-2 (Using Stack)
        //T.C = O(n) = S.C

        stack<int> st;
        st.push(-1); // Base boundary
        int maxLen = 0;

        for (int i=0 ; i<s.length() ; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Reset base boundary to current index
                } 
                else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};