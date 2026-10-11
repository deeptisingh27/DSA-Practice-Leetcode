class Solution {
public:
    int minInsertions(string s) {    
        //Approach (Greedy)
        //T.C = O(n) , S.C = O(1)

        int n = s.length();
        int ans = 0; //insertions

        int count = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } 
            else { //')'
                if(count > 0) { //check if this closing bracket had opening bracket
                    count--;
                } 
                else {
                    ans++; //adding a '('
                }

                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } 
                else {
                    ans++; //adding a ')'
                    i++;
                }
            }
        }

        return ans + count*2; //agr count(open brackets) bach gaye toh har open bracket ke liye 2 closing bracketbhi add kro ans me
    }
};
