class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (int)s.size();
        if (k > n) return false;

        int need = 1 << k;
        if (n - k + 1 < need) return false;

        vector<char> seen(need, 0);
        int got = 0;

        int mask = need - 1;
        int x = 0;

        // build first window
        for (int i = 0; i < k; i++) x = (x << 1) | (s[i] - '0');
        seen[x] = 1; got = 1;

        // roll
        for (int i = k; i < n; i++) {
            x = ((x << 1) & mask) | (s[i] - '0');
            if (!seen[x]) {
                seen[x] = 1;
                got++;
                if (got == need) return true;
            }
        }
        return got == need;
    }
};