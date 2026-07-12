class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //

        int n = arr.size();

        vector<int> temp(arr);
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> mp;
        int currRank = 1;

        //assign ranks to unique elements only
        for (int num : temp) {
            if (mp.find(num) == mp.end()){ //!mp.count(num)
                mp[num] = currRank++;
            }
        }

        //replace each element in the original array with its rank
        for (int &num : arr) {
            num = mp[num];
        }

        return arr;
    }
};