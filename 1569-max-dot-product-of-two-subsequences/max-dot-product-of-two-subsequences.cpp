#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> currentDp(m + 1, INT_MIN);
        vector<int> previousDp(m + 1, INT_MIN);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int product = nums1[i - 1] * nums2[j - 1];

                currentDp[j] = max({
                    product,                                
                    previousDp[j],                          
                    currentDp[j - 1],                       
                    product + max(0, previousDp[j - 1])     
                });
            }
            
            swap(currentDp, previousDp);
        }

        return previousDp[m];
    }
};