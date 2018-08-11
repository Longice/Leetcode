class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < nums.size()-3; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j = i+1; j < nums.size()-2; ++j)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int l = j+1, r = nums.size()-1;
                while(l < r){
                    if(nums[j] + nums[l] + nums[r] == target - nums[i]){
                        result.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++; r--;
                    }else if(nums[j] + nums[l] + nums[r] < target - nums[i])
                        l++;
                    else r--;
                }
            }
        }
        return result;
    }
};
