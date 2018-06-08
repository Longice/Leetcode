class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0) {
            int y = x % 10;
            int updatedResult = result * 10 + y;
            if((updatedResult - y) / 10 != result)
                return 0;
            result = updatedResult;
            x = x / 10;
        }
        return result;
    }
};
