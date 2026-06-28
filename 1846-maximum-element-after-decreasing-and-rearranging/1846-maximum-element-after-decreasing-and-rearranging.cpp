class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        // T.C. = O(n log n) : sorting

        int n = arr.size();

        sort(arr.begin(), arr.end());
        
        arr[0] = 1; //1st element always 1

        for(int i=1 ; i<n ; i++){
            arr[i] = min(arr[i], arr[i-1] + 1);
        }

        return arr[n-1]; //last element must be maximum
    }
};