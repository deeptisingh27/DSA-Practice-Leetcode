class Solution {
public:
    int maximumLength(vector<int>& nums) {

        //T.C = O(n) = S.C

        unordered_map<long long, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        int ans = 1;

        for(auto &f : freq){ //for(auto &[num, count] : freq)
            long long num = f.first;
            int count = f.second;  

            if (num == 1) { //special case
                ans = max(ans, (count % 2) ? count : count-1);
                continue;
            }

            long long curr = num;
            int len = 0;

            while (freq.count(curr) && freq[curr] >= 2){
                len += 2;

                if (curr > LLONG_MAX / curr) break;
                
                curr *= curr;
            }

            //curr cannot be used twice anymore
            if (freq.count(curr))
                len += 1;
                
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};