class Solution {
public:
    bool canAliceWin(int n) {
        int toRemove = 10;
        bool alice = true;

        if(n<toRemove) return false;

        while(n >= toRemove && toRemove > 0){
            n -= toRemove;
            toRemove -= 1;
            alice = !alice; //switch turns
        }

        //if the loop exits on Alice's turn, she couldn't make a move and loses, if it exits on Bob's turn, Bob couldn't move, so Alice wins.
        return !alice;
    }
};