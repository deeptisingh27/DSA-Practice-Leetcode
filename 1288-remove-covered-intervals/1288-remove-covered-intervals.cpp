class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        //T.C O(n logn) , S.C = O(1)

        //Sort by start increasing, if starts are same then sort by end decreasing
        auto lambda = [](vector<int> vec1, vector<int> vec2){
            if(vec1[0] == vec2[0])
                return vec1[1] > vec2[1];

            return vec1[0] < vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        int lastIntervalEnd = intervals[0][1]; //end point of the last non-covered interval
        int count = 1; //first interval is always counted
        
        for(auto &interval : intervals){

            //current interval is covered
            if(interval[1] <= lastIntervalEnd)
                continue;

            //current interval is not covered
            lastIntervalEnd = interval[1];
            count++;
        }

        return count;
    }
};