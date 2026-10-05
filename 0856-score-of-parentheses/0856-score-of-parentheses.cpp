class Solution {
public:
    int scoreOfParentheses(string s) {
        //T.C = S.C = O(n)
        
        int n = s.length();
        stack<int> st;

        int score = 0;

        for (int i=0 ; i<n ; i++) {
            char ch = s[i];

            if (ch == '(') {
                st.push(score);
                score = 0;
            } 

            else{ //ch == ')'
                if (s[i-1] == '(') { //"()" -> +1 point
                    score = st.top() + 1;
                } 
                else{ //s[i-1] == ')'
                    // had content inside -> double it
                    score = st.top() + (2 * score);
                }

                st.pop();
            }
        }

        return score;
    }
};