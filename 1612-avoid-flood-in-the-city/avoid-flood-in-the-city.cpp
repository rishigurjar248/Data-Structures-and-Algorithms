class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zer; 
        int n = rains.size();
        vector<int> ans(n, -1); 
               unordered_map<int, int> M; 

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                zer.insert(i);
                ans[i] = 1; 
            } else {
                int lake = rains[i]; 
                if (M.find(lake) != M.end()) {
                    int lastRainDay = M[lake]; 
                    auto up = zer.upper_bound(lastRainDay);
                    if (up == zer.end()) { 
                        return {};
                    }
                    ans[*up] = lake;
                    zer.erase(up);
                }
                M[lake] = i;
            }
        }
        return ans;
    }
};