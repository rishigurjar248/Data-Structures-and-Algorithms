class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        int s = 0;
        for(int i = 0; i < k; i++) s += c[i];
        int a = s;
        for(int i = 1; i <= k; i++) {
            s -= c[k - i];
            s += c[n - i];
            a = max(a, s);
        }
        return a;
    }
};