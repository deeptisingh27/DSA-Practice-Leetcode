class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkipLength;

        string ans;

        for(char &ch : s){
            if(ch == '('){
                lastSkipLength.push(ans.length());
            }

            else if(ch == ')'){
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(ans.begin() + l, ans.end());
            }

            else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};