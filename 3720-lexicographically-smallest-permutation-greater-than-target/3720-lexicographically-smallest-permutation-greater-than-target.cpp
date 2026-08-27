class Solution {
public:
    bool solve(string& curr, vector<int>& count, string& target, string& ans, int i, bool greater){
        if(i == target.length()){
            if(greater){
                ans  = curr;
                return true;
            }

            return false;
        }

        for(char ch='a' ; ch <= 'z' ; ch++){
            if(count[ch-'a'] == 0) //this char does exist
                continue;

            if(greater == false && ch < target[i])
                continue;

            //do
            curr.push_back(ch);
            count[ch-'a']--;

            //explore
            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, ans, i+1, isGreater))
                return true;

            //undo
            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        //T.C : O(26 * n) , where n is the length of s
        //S.C : O(n) = O(26) freq array + O(n) curr string + O(n) recursion stack
        
        vector<int> count(26, 0);
        for( char &ch : s){
            count[ch-'a']++;
        }

        string curr = "";
        string ans = "";

        solve(curr, count, target, ans, 0, false);

        return ans;
    }
};