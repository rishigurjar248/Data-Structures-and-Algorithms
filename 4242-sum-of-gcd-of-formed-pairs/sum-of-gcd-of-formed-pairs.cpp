class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxx = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] > maxx) maxx = nums[i];
            nums[i] = __gcd(nums[i], maxx);
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        long long sum = 0;
        while(i < j){
            sum += __gcd(nums[i++], nums[j--]);
        }
        return sum;
    }
};