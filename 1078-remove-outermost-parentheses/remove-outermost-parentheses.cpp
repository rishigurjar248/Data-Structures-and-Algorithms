class Solution {
public:
    string removeOuterParentheses(string s) {

        int k = 0;    
        int op = 0;   

        for (auto& e : s) {
            if (op > 0 && e == ')')
                op--;              

            if (op > 0)
                s[k++] = e;        

            if (e == '(')
                op++;             
        }

        s.resize(k);               
        return s;
    }
};