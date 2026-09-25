class Solution {
public:
    int i = 0;

    // Parses: Factor ("*" Factor)*
    set<string> parseTerm(const string& s) {
        set<string> res = {""}; // multiplicative identity (Cartesian product with {""} keeps words intact)
        
        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> next_factor = parseFactor(s);
            set<string> combined;
            for (const string& a : res) {
                for (const string& b : next_factor) {
                    combined.insert(a + b);
                }
            }
            res = move(combined);
        }
        return res;
    }

    // Parses: Term ("," Term)*
    set<string> parseExpr(const string& s) {
        set<string> res;
        
        while (true) {
            set<string> term = parseTerm(s);
            res.insert(term.begin(), term.end()); // Union
            
            if (i < s.size() && s[i] == ',') {
                i++; // consume ','
            } else {
                break;
            }
        }
        return res;
    }

    // Parses: lowercase letters or '{' Expr '}'
    set<string> parseFactor(const string& s) {
        if (s[i] == '{') {
            i++; // consume '{'
            set<string> res = parseExpr(s);
            i++; // consume '}'
            return res;
        } else {
            string word = "";
            while (i < s.size() && isalpha(s[i])) {
                word += s[i++];
            }
            return {word};
        }
    }
    
    vector<string> braceExpansionII(string expression) {
        i = 0;
        set<string> resultSet = parseExpr(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};