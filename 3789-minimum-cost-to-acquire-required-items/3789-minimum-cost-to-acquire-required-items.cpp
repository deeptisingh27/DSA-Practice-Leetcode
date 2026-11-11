class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both = min(need1, need2);

        // Option 1: Common + individual items
        long long ans1 = both*costBoth + (need1-both)*cost1 + (need2-both)*cost2;

        // Option 2: Only type 3 items
        long long ans2 = (long long)max(need1, need2) * costBoth;

        // Option 3: Buy everything separately
        long long ans3 = (long long)need1 * cost1 + (long long)need2 * cost2;

        return min({ans1, ans2, ans3});
    }
};