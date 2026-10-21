class Solution {
public:
    int minOperations(string s) {
        string s1 = s; //copy of string s
        sort(s1.begin(), s1.end());

        if(s == s1) return 0;

        if(s.length() == 2) return -1;

        if((s1[0] == s[0]) || (s1.back() == s.back())) return 1;

        if(s.find(s1[0]) == s.size()-1 && s.rfind(s1.back()) == 0) return 3;

        else return 2;
    }
};