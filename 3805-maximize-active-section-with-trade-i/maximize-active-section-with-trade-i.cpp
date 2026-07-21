class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        // storing count of contiguous zero's exteding from i
        vector<int> suf(n+1, 0);
        int pre = 0, ans = 0, cnt = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0')  suf[i] = 1 + suf[i+1];
            cnt += (s[i] == '1');
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(i <= 0 || s[i-1] == '1') continue;
                while(i < n-1 && s[i] == '1') i++;
                // Only take when 0110 or 010 case not 0111
                if(i <= n-1 && s[i] == '0') ans = max(ans, (pre + suf[i]));
                pre = s[i] == '0' ? 1 : 0;
            }
            else pre++;
        }
        return cnt + ans;
    }
};