class Solution {
public:

    int solve(vector<int> v)
    {
        int diff=0;
        for(int i=0;i<v.size();i++)
        {
            int st = v[i]; //consider start of consecutive series from here
            int j = i;
            while(j+1<v.size() && v[j]+1==v[j+1]){
                j++; 
            }
            diff=max(diff,j-i+1);
            i=j;
        }

        return diff+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        vector<int> v1 = hBars;
        vector<int> v2 = vBars;

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        

        if(v1[v1.size()-1]==n+2) v1.pop_back();
        if(v2[v2.size()-1]==m+2) v2.pop_back();


        int diff1 = solve(v1);
        int diff2 = solve(v2);

        int mnval = min(diff1,diff2);

        return mnval*mnval;

    }
};