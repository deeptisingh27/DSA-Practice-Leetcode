class Solution {
public:
    string removeDuplicates(string s) {
        // Time: O(n) , Space: O(n)

        string ans = ""; // Acts as a stack

        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};