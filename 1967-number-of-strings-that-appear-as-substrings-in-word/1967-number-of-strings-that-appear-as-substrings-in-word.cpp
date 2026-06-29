class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        // T.C. = O(n * m * k) (worst case)
        // n = number of patterns, m = length of word, k = average length of a pattern

        // S.C. = O(1)
        
        int count=0;

        for(string &pattern : patterns){

            //if the current pattern exists as a substring of word
            if(word.find(pattern) != string::npos) 
                count++;
        }

        return count;
    }
};

//find() on a string returns the starting index of the substring if found, otherwise it returns string::npos
//find() on  containers like set or map returns an iterator, so it should be compared with .end()