class Solution {
public:
    void dfs(TreeNode* root, int lvl, vector<int>& sum) {
        if (!root) return;
        if (lvl > sum.size()) sum.push_back(0);
        sum[lvl - 1] += root->val;
        dfs(root->left, lvl + 1, sum);
        dfs(root->right, lvl + 1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(root, 1, sum);
        int maxi = INT_MIN, ans = 1;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > maxi) {
                maxi = sum[i];
                ans = i + 1;
            }}
        return ans;
    }
};