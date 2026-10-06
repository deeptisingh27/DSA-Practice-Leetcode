class Solution {
public:
    int minSwaps(string s) {
        //T.C = O(n) , S.C = O(n)
        
        stack<int> st;

        for(char &ch : s){
            if(ch == '[')
                st.push(ch);
            else if(!st.empty())
                st.pop();
        }
        
        return (st.size() + 1) / 2;
    }
};