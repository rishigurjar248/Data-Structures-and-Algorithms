class Solution {
public:
    int maximumDifference(vector<int>&nums) {
        int maxdiff=-1; 
        int mini=nums[0];
        for (int i=1;i<nums.size();++i){
            if(nums[i]>mini){
                maxdiff = max(maxdiff, nums[i] - mini);
            }
            
            mini = min(mini, nums[i]);
        }
        
        return maxdiff;
    }
};