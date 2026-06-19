class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double total_hour = double(hour) + double(minutes)/60;
        
        //12 hr -> 360 degrees
        //1 hr  -> 30 degress
        //x hr  -> x*30;
        double angle_hour_hand = total_hour*30;
        
        //60 min -> 360 degrees
        //1 min  -> 6 degrees
        //y min  -> y*6        
        double angle_minute_hand = minutes*6;
        
        double ans = abs(angle_minute_hand - angle_hour_hand);
        
        if(ans > 180)
            return 360-ans;

        return ans;
    }
};