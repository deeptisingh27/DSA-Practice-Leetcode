class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to form a valid minimal interval starting with each character
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                if (first[c] < left) {
                    // Encountered a character that starts before our interval,
                    // which means this interval cannot be a new independent valid interval.
                    valid = false;
                    break;
                }
                right = max(right, last[c]);
            }

            if (valid) {
                intervals.push_back({right, left}); // Store as {end, start} for sorting
            }
        }

        // Sort intervals by their end index
        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (const auto& [end, start] : intervals) {
            if (start > prev_end) {
                result.push_back(s.substr(start, end - start + 1));
                prev_end = end;
            }
        }

        return result;
    }
};