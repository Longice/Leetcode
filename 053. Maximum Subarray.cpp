// 连续子数组的最大和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if (cur_sum <= 0)
                cur_sum = nums[i];
            else
                cur_sum += nums[i];
            if (cur_sum > max_sum)
                max_sum = cur_sum;
        }
        return max_sum;
    }
};
// 看了100%的这几行代码，可以让程序变快4ms……
// https://blog.csdn.net/qq_32320399/article/details/81518476
static const auto fast = []() {
	std::ios::sync_with_stdio( false );
	std::cin.tie( nullptr );
	return nullptr;
}( );

