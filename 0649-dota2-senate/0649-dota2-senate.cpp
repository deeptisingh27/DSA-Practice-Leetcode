class Solution {
public:
    /*
    bool removeSenator(string &senate, char ch, int idx) {
        bool loopAround = false;
        
        while(true) {
            
            if(idx == 0) {
                loopAround = true;
            }
            
            if(senate[idx] == ch) {
                senate.erase(begin(senate) + idx);
                break;
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return loopAround;
    }
    */

    string predictPartyVictory(string senate) {

        /*
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = senate.length() - R_Count;        
        
        int idx = 0;
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(senate[idx] == 'R') {
                bool checkRemoval = removeSenator(senate, 'D', (idx+1)%(senate.length()));
                D_Count--;
                if(checkRemoval) idx--;
            } 
            
            else {
                bool checkRemoval = removeSenator(senate, 'R', (idx+1)%(senate.length()));
                R_Count--;
                if(checkRemoval) idx--;
                
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        */



        int n = senate.length();
        
        queue<int> queR;
        queue<int> queD;
        
        for(int i = 0; i<n; i++) {
            if(senate[i] == 'R')
                queR.push(i);
            else
                queD.push(i);
        }
        
        while(!queR.empty() && !queD.empty()) {
            
            int R_idx = queR.front(); queR.pop();
            int D_idx = queD.front(); queD.pop();
            
            if(R_idx < D_idx) {
                queR.push(R_idx+n);
                //Why +n ?
                //Do this dry run on "RDD"
            } else {
                queD.push(D_idx+n);
                //Why +n ?
                //Do this dry run on "RDD"
            }
            
        }
        
        return queR.empty() ? "Dire" : "Radiant";
    }
};