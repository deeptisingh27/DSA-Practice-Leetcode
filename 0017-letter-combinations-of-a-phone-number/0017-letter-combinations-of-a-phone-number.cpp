class Solution {
private:
    void solve(string& digits, string& temp, int idx, vector<string>& ans,                  unordered_map<char, string> mp ) {
        
        //base case
        if (idx >= digits.length()) {
            ans.push_back(temp);
            return;
        }
        
        char ch = digits[idx];

        string str = mp[ch];
        
        for(int i=0 ; i<str.length() ; i++) {
            temp.push_back(str[i]); //do
            solve(digits, temp, idx+1, ans, mp); //explore
            temp.pop_back(); //undo
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        //T.C.= O(n * 4^n) , S.C. = O(n)

        vector<string> ans;
        string temp = "";

        unordered_map<char, string> mp;
        mp['0'] = "";
        mp['1'] = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, temp, 0, ans, mp);

        return ans;
    }
};