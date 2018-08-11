class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, digit = 0;
        int i = 0, len = str.length();
        while (i < len && str.at(i) == ' ') { i++; }
        if(i < len && str.at(i) == '-'){
            sign = -1;
            ++i;
        } else if (i < len && str.at(i) == '+'){
            sign = 1;
            ++i;
        }
        while(i < len && str.at(i) >= '0' && str.at(i) <= '9'){
            if(digit > INT_MAX / 10 || (digit == INT_MAX / 10 && str.at(i) > '7')){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            digit = digit * 10 + str.at(i++) - '0';
        }
        return digit * sign;
    }
};
