class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            /*
            // Open barckets: stack me push
            // Close brackets: stack ke top ko check & then pop
            
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            else {
                if (st.empty()) return false;

                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }

            */


            if(ch == '('){
                st.push(')');
            }
            else if(ch == '{'){
                st.push('}');
            }
            else if(ch == '['){
                st.push(']');
            }
            else if (st.empty() || st.top() != ch){
                return false;
            }
            else{
                st.pop();
            }            
        }

        return st.empty(); // If stack is empty, all brackets matched
    }
};