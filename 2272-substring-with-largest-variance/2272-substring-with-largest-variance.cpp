class Solution {
public:
    int largestVariance(string s) {

        //KADANE'S ALGORITHM
        //T.C = O(26 *26 * n) = O(n) , S.C. = O(26) = O(1)

        int ans = 0;

        //stores if 'a' to 'z' is present in s
        vector<int> count(26, 0); 

        for(char &ch : s){
            count[ch-'a'] = 1;
        }
        
        // try every ordered pair of characters
        for(char first='a' ; first<='z' ; first++){
            for(char second='a' ; second<='z' ; second++){

                // skip if either character does not exist
                if(count[first-'a'] == 0 || count[second-'a'] == 0) continue;

                // frequency of 1st and 2nd char
                int firstCount = 0; 
                int secondCount = 0; 

                bool pastSecond = false; // if second char occured in the past

                // Modified Kadane's Algorithm
                for(char &ch : s){
                    if(ch == first) firstCount++;

                    if(ch == second) secondCount++;

                    // valid substring contains at least one 'second'
                    if(secondCount > 0){
                        ans = max(ans, firstCount-secondCount);
                    } 
                    // current substring has no 'second', but one existed before reset
                    else if(pastSecond){
                        ans = max(ans, firstCount-1);
                    }

                    if(secondCount > firstCount){ //-ve variance -> reset 
                        firstCount = 0;
                        secondCount = 0;
                        pastSecond = true;
                    }
                }
            }
        }

        return ans;
    }
};