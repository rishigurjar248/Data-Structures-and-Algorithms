class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0; 
        vector<int> lastIndex(128, -1); 
        int start = 0;  

        for (int end = 0; end < n; end++) { 
            start = max(start, lastIndex[s[end]] + 1); 
            res = max(res, end - start + 1); 
            lastIndex[s[end]] = end;
        }
        return res;
    }
};