class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int y=0;
        int z = x;
        while(z > 0){
            int t = z % 10;
            y = y * 10 + t;
            z = z / 10;
        }
        return y==x;
    }
};

# Approach 2
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x != 0))
            return false;
        int y=0;
        while(x > y){
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return x == y || x == y/10;
    }
};
