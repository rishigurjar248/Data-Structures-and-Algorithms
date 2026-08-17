#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[501][501];
    
    int solve(int left, int right, const vector<int>& prefixSum) {
         if (left == right) {
            return 0;
        }
        
         if (memo[left][right] != -1) {
            return memo[left][right];
        }
        
        int maxScore = 0;
        
         for (int mid = left; mid < right; ++mid) {
             int leftSum = prefixSum[mid + 1] - prefixSum[left];
             int rightSum = prefixSum[right + 1] - prefixSum[mid + 1];
            
            if (leftSum < rightSum) {
                 maxScore = max(maxScore, leftSum + solve(left, mid, prefixSum));
            } 
            else if (leftSum > rightSum) {
                 maxScore = max(maxScore, rightSum + solve(mid + 1, right, prefixSum));
            } 
            else {
                 int keepLeft = leftSum + solve(left, mid, prefixSum);
                int keepRight = rightSum + solve(mid + 1, right, prefixSum);
                maxScore = max({maxScore, keepLeft, keepRight});
            }
        }
        
        return memo[left][right] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        
         vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        
        return solve(0, n - 1, prefixSum);
    }
};