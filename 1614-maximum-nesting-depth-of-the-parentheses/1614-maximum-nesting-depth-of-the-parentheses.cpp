class Solution {
public:
    int maxDepth(string s) {
        //T.C = O(n) , S.C = O(1)
        
        int curr_depth = 0;
        int max_depth = 0;

        for(char &ch : s){
            if(ch == '('){
                curr_depth++;
                max_depth = max(max_depth, curr_depth);
            }

            else if(ch == ')'){
                curr_depth--;
            }
        }

        return max_depth;
    }
};