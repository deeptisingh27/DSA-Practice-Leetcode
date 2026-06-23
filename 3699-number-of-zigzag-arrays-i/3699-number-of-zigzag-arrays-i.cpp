class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1, 0), down(m + 1, 0);

        // length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m + 1, 0),
                              newDown(m + 1, 0);

            // newUp[v] = sum_{u < v} down[u]
            long long pref = 0;
            for (int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            // newDown[v] = sum_{u > v} up[u]
            long long suff = 0;
            for (int v = m; v >= 1; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};

//CHAAPA HAI GPT SE