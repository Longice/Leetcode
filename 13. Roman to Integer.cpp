class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        
        int preValue = 0, result = 0;
        for(int i=s.size()-1; i >= 0; --i){
            int value = dict[s[i]];
            if(value < preValue)
                result -= value;
            else
                result += value;
            preValue = value;
        }
        return result;
    }
};
