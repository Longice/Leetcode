class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result;
        int gap = INT_MAX;
        for(int i = 0; i < nums.size()-2; ++i){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                if(abs(nums[i] + nums[l] + nums[r] - target) < gap){
                    gap = abs(nums[i] + nums[l] + nums[r] - target);
                    result = nums[i] + nums[l] + nums[r];
                } 
                if(nums[i] + nums[l] + nums[r] > target)
                    r--;
                else
                    l++;
            }
        }
        return result;
    }
};
