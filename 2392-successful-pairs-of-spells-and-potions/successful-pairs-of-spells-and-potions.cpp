class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            // for(int j = 0; j < m; j++){
            //     if((long long)spells[i] * (long long)potions[j] >= success) cnt++;
            // }
            int low = 0;
            int high = m-1;
            while(low <= high){
                int mid = (low + high)/2;
                if((long long)spells[i] * (long long)potions[mid] >= success) high = mid-1;
                else low = mid+1;
            }
            ans.push_back(m-low);
        }
        return ans;
    }
};