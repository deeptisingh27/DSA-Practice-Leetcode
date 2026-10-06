class Solution {
public:
    int minAddToMakeValid(string s) {
        //Approach-1 (Using stack)
        //T.C = O(n) = S.C
        
        stack<int> st;
        int open = 0;

        for(char &ch : s){
            if(ch == '(')
                st.push(ch);
            else if(!st.empty())
                st.pop();
            else
                open++;
        }
        
        return open + st.size();        
    }
};