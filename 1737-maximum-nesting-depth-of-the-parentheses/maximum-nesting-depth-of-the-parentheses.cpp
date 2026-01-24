class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                 count++;
                 maxx=max(maxx,count);

            }
            if(s[i]==')'){
                 count--; 
            if(count<0) count=0;
            }

        }
        return maxx;
    }
};