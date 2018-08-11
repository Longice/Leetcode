class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxS = 0, l = 0, r = height.size()-1;
        while(l < r){
            int s = min(height[l], height[r]) * (r - l);
            maxS = max(maxS, s);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxS;
    }
};
