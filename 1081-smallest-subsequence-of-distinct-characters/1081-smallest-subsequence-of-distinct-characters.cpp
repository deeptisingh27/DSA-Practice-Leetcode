class Solution {
public:
    string smallestSubsequence(string s) {
        //T.C = O(n) , S.C = O(26) = O(1)

        vector<int> lastIndex(26);
        vector<bool> taken(26, false);
        
        string ans;

        for(int i=0 ; i<s.length() ; i++){
            lastIndex[s[i]-'a'] = i;
        }

        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i];
            int idx = ch-'a';

            if(taken[idx]) continue;

            while(ans.length() > 0 && ans.back() > ch && lastIndex[ans.back() - 'a'] > i){
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            taken[idx] = true;
        }

        return ans;
    }
};