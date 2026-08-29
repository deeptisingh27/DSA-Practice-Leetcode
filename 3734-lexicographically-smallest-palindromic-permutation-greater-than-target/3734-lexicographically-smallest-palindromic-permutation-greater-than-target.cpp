class Solution {
public:

    char midChar = '$';
    int half = 0;

    bool solve(string& curr, vector<int>& count, string& target, string& ans, int i, bool greater) {
        if (i == half) {

            string candidate = curr; //left Half
            string rightHalf = candidate;
            reverse(rightHalf.begin(), rightHalf.end()); //right half
            
            if(midChar != '$')
                candidate += midChar; //mid character

            candidate += rightHalf;

            if (candidate > target) {
                ans = candidate;
                return true;
            }

            return false;
        }

        for (char ch='a' ; ch<='z' ; ch++) {
            if (count[ch-'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            //do
            curr.push_back(ch);
            count[ch - 'a']--;

            //explore
            bool isGreater = greater || ch > target[i];
            if (solve(curr, count, target, ans, i+1, isGreater))
                return true;

            //undo
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char &ch : s) 
            count[ch-'a']++;

        int oddCount = 0;
        for (int c=0 ; c<26 ; c++) {
            if (count[c] % 2 == 1) { 
                oddCount++; 
                midChar = c + 'a'; 
            }
        }
        if (oddCount > 1) 
            return "";

        // Left-half counts + middle char (only when n is odd)
        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        string curr = "";
        string ans = "";

        solve(curr, halfCount, target, ans, 0, false);

        return ans;  
    }
};