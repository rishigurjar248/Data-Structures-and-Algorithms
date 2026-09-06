class Solution {
public:
    int match(int i, int j, string s, string t, vector<vector<int>>&dp){
        cout<<i<<" "<<j<<"\n";
        if(i>0 && j==0)return 0;
        if(i>j)return 0;
        if(i>=0 && j>=0 && dp[i][j]!=-1)return dp[i][j];
        
        int ans=match(i, j-1, s, t,dp);
        if(t[i-1]==s[j-1])ans+=match(i-1, j-1, s, t,dp);
        dp[i][j]=ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        int n=t.size();
        int m=s.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        //dp[i][j]-->find a match from i backwards and j backwarsd
        for(int x=0;x<=m;x++){
            dp[0][x]=1;
        }
        return match(n, m, s, t, dp);
    }
};