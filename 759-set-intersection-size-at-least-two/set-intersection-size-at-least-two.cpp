class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& A, const vector<int>& B){
            if (A[1] != B[1]) return A[1] < B[1];
            return A[0] > B[0];
        });
        
        int a = -1e9, b = -1e9;
        int ans = 0;
        for (auto &iv : intervals) {
            int l = iv[0], r = iv[1];
            if (l > b) {
                ans += 2;
                a = r - 1;
                b = r;
            } else if (l > a) {
                ans += 1;
                a = b;
                b = r;
            } else {}
        }
        return ans;
    }
};