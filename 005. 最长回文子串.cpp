// Approach1 Time:O(n3) Space:O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start=0, end=-1;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                int m = j - i;
                bool flag = true;
                for(int k = 0; k <= m/2; ++k) {
                    if(s[i+k] != s[j-k]) {
                        flag = false;
                        break;
                    }    
                }
                if(flag & m > end-start) {
                    start = i;
                    end = j;
                }
            }
        }
        string longest;
        for(int i = start; i <= end; ++i){
            longest += s[i];
        }
        return longest;
    }
};


// Approach2 T:O(n2) S:O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = -1;
        
        for(int i = 0; i < n; ++i){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end-start+1);
    }

private:
        int expandAroundCenter(string s, int left, int right) {
            
            while(left >= 0 & right < s.length() & s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;   // right-1 - (left+1) + 1
        } 
};
