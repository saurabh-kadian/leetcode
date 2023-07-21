class Solution {
public:
    int maxLen = 1;
    int lo = 0;
    unordered_map<string, bool> cache;
    bool solve(int i, int j, string& s){
        string empty = "";
        // two length substring
        if(j == i + 1){
            if(s[i] == s[j]){
                if(maxLen < j-i+1){
                    maxLen = j-i+1;
                    lo = i;
                }
                return true;
            }
            return false;
        }
        // 1 length substring
        if(i == j){
            if(maxLen < j-i+1){
                lo = i;
                maxLen = j-i+1;
            }
            return true;
        }

        // memoization
        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();
        if(cache.find(key) != cache.end())
            return cache[key];
        
        // ignore j
        bool left = solve(i, j-1, s);
        // ignore i
        bool right = solve(i+1, j, s);
        // if both match
        if(s[i] == s[j]){
            bool mid = solve(i+1, j-1, s);
            // new max maybe?
            if(mid == true){
                if(maxLen < j-i+1){
                    lo = i;
                    maxLen = j-i+1;
                }
                return true;
            }
            return false;    
        }
        return false;
    }
    string bottomUp(string s){
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int low = 0;
        int maxLen = 1;
        for(int i = s.size()-1;i >= 0;--i){
            for(int j = 0;j < s.size();++j){
                if(i > j)
                    continue;
                if(i == j){
                    dp[i][j] = true;
                    continue;
                }
                if(j == i + 1){
                    dp[i][j] = (s[i] == s[j]);
                    if(dp[i][j] && maxLen < j-i+1)
                        maxLen = j-i+1, low = i;
                    continue;
                }
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(maxLen < j-i+1)
                        maxLen = j-i+1, low = i;
                    continue;
                }
            }
        }
        return s.substr(low, maxLen);
    }
    string fromTheCenter(string s){
        if(s.size() == 1)
            return s;
        
        int low = 1;
        int maxLen = 1;
        for(int c = 0;c < s.size();++c){
            int left = c-1;
            int right = c+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                if(right-left+1 > maxLen)
                    maxLen = right-left+1, low = left;
                left--;
                right++;
            }
            if(c+1 < s.size() && s[c] == s[c+1]){
                if(maxLen < 2)
                    maxLen = 2, low = c;
                left = c-1;
                right = c+2;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    if(right-left+1 > maxLen)
                        maxLen = right-left+1, low = left;
                    left--;
                    right++;
                }   
            }
        }
        return s.substr(low, maxLen);
    }
    string longestPalindrome(string s) {
        return fromTheCenter(s);
        // return bottomUp(s);
        // solve(0, s.size()-1, s);
        // return s.substr(lo, maxLen);
    }
};