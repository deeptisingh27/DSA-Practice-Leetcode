class Solution {
public:
    bool hasAllCodes(string s, int k) {

        //T.C = O(n*k) , S,C = O(2^k * k)

        int n = s.size();
        unordered_set<string> st;   
        int total_binary_code = pow(2,k); //1<<k

        for(int i=k ; i<=n ; i++){
            string sub = s.substr(i-k , k); //s.substr(int startIndex, int length)

            st.insert(sub);

            if(st.size() == total_binary_code) return true;
        }

        return false;
    }
};