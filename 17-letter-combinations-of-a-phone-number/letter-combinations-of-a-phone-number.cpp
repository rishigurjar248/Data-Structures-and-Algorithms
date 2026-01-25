class Solution {
public:
    void solve(string digits, int i, vector<string>& ans, string output, string mapp[]){
        if(i >= digits.length()){
            ans.push_back(output);
            return;
        }

        int num = digits[i] - '0';
        string values = mapp[num];

        for(int j=0; j<values.length(); j++){
            output.push_back(values[j]);

            solve(digits, i+1, ans, output, mapp);

            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        string mapp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, ans, output, mapp);

        return ans; 
    }
};