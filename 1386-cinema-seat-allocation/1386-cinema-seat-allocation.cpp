class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //approach 1

        /*
        unordered_map<int, unordered_set<int>> mp; //row -> reserved seats of that row

        for(auto & reservedSeat : reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }

        int ans = (n - mp.size()) * 2; //rows with no reserved seats can make grp A and C

        for(auto& [row, bookedSeats] : mp){

            // Helper lambda to check if a specific seat is unreserved
            auto isAvailable = [&](int seat){
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool grpA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool grpB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool grpC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(grpA && grpC) 
                ans += 2;

            else if(grpA | grpB || grpC) 
                ans += 1;            
        }

        return ans;
        */


        //approach 2

        //row -> bitmask representing its reserved seats(10-bit integer)
        unordered_map<int, int> mp; 

        for(auto& reservedSeat : reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row] |= (1 << seat); //set the corresponding bit for the reserved seat
        }

        int ans = (n - mp.size()) * 2; //rows with no reserved seats can make grp A and C

        // Bitmasks for the 3 grps using bitwise OR '|'
        int maskA = (1<<2) | (1<<3) | (1<<4) | (1<<5);
        int maskB = (1<<4) | (1<<5) | (1<<6) | (1<<7);
        int maskC = (1<<6) | (1<<7) | (1<<8) | (1<<9);

        for(auto& [row, bookedSeatsMask] : mp){

            bool grpA = (bookedSeatsMask & maskA) == 0;
            bool grpB = (bookedSeatsMask & maskB) == 0;
            bool grpC = (bookedSeatsMask & maskC) == 0;

            if(grpA && grpC) 
                ans += 2;

            else if(grpA | grpB | grpC) 
                ans += 1;            
        }

        return ans;
    }
};