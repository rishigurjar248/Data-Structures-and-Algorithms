class Solution {
public:
    int maxDifference(string s) {
      unordered_map<char, int> m;

        for (char c : s) {
            m[c]++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        for (auto &[ch, freq] : m) {
            if (freq % 2 == 0)
                minEven = min(minEven, freq);
            else
                maxOdd = max(maxOdd, freq);
        }
        if (maxOdd == INT_MIN || minEven == INT_MAX)
            return 0;

        return maxOdd - minEven;  
    }
};