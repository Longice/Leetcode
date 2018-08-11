class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows];
        int len = s.length();
        int i = 0; 
        while(i < len) {
            for(int r = 0; r < numRows & i < len; ++r) {
                arr[r] += s[i++];
            }
            for(int r = numRows-2; r >= 1 & i < len; --r) {
                arr[r] += s[i++];
            }
        }
        
        for(int i = 1; i < min(len, numRows); ++i) {
            arr[0] += arr[i];
        }
        return arr[0];
    }
};
