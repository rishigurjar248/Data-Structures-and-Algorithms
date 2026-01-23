class Solution {
public:
    string largestOddNumber(string s) {
               int indexes = -1;
        for (int i=s.length()-1;i>=0;i--){
            if((s[i]-'0')%2==1){
                indexes=i;
                break;
            }
        }

         int i = 0;
        while (i<=indexes&&s[i]=='0')i++;
        return s.substr(i,indexes-i+1);
    }
};