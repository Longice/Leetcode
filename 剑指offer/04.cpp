// 二维数组中的查找， p44

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        int i = 0, j = array[0].size() - 1;
        while(i < array.size() && j >=0){
            if(array[i][j] == target)
                return true;
            else if(array[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};
