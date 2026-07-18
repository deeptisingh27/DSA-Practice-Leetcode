class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        //T.C = O(n) , S.C = O(1)

        int n = s.size();
        unordered_set<char> st;

        int i = 0;
        int j = 0;

        int ans = 0;

        for(j=0 ; j<n ; j++){

            //remove characters until s[j] is no longer a duplicate
            while (st.count(s[j])){ //st.find(s[j] != st.end())
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};