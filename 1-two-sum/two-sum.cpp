class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
    for (int i=0;i<n;i++) {
        int a=nums[i];
        int leftout=target-a;
        if(mpp.find(leftout)!=mpp.end()) {
            return {mpp[leftout],i};
        }
        mpp[a]=i;
    }
    return{-1,-1};
        
    }
};