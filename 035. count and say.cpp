class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        
        string x = countAndSay(n-1);
        
        string result = "";
        int cnt = 0;
        for(int i=0; i<x.size(); ++i){
            cnt++;
            if (i == x.size()-1 || x[i] != x[i+1]){
                result += (cnt+48);  // 用std::to_string时时间和空间效率较低。cnt貌似不会大于9
                result += x[i];
                cnt = 0;
            }
        }
        return result;
    }
};
