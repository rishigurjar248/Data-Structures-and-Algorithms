class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        int mini = nums[0];
        int maxi = nums[0];

        for(int val : nums){
            mini = min(mini, val);
            maxi = max(maxi, val);
        }

        for(int i = mini+1; i < maxi; i++){
            if(find(nums.begin(), nums.end(),i) == nums.end()){
                missing.push_back(i);
            }
        }
        return missing;
    }
};