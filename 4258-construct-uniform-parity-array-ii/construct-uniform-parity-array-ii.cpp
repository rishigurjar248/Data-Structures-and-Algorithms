class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size(),mn=INT_MAX;
        for (int i:nums1) {
            if ((i%2) == 1) {
                mn = min(mn, i);
            }
        }
        if (mn == INT_MAX)return true;
        for (int x : nums1) {
            if (x % 2 == 0 && x < mn)
            return false;
        }
        return true;
    }
};