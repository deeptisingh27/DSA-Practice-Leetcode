class Solution {
public:
    int minAddToMakeValid(string s) {
        //Approach-1 (Using stack)
        //T.C = O(n) = S.C

        /*
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

        */


        //Approach-2 (without using stack)
        //T.C = O(n) , S.C = O(1)      

        int size = 0;
        int open = 0;

        for(char &ch : s) {
            if(ch == '(') {
                size++;
            } else if(size > 0) {
                size--;
            } else {
                open++;
            }
        }

        return open + size;
    }
};