class Solution {
public:
    unordered_map<int, int> cache;
    int solve(int index, string& s){
        if(index > s.size()  || 
            s[index] == '0'  ||
            (index == s.size() - 1 && s[index] == '0'))         return 0;        
        if(index == s.size() || index == s.size() -1)           return 1;

        if(cache.count(index))
            return cache[index];

        int answer = solve(index + 1, s);
        if(s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')){
            answer += solve(index + 2, s);
        }
        return cache[index] = answer;
    }
    int bu(string s){
        int dp[105] = {0};
        for(int i = s.size();i >= 0;--i){
            if(i == s.size()){
                dp[i] = 1;
                continue;
            }
            if(i == s.size() - 1){
                dp[i] = (s[i] == '0' ? 0 : 1);
                continue;
            }
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1];
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                dp[i] += dp[i+2]; 
        }
        return dp[0];
    }
    int numDecodings(string s) {
        return bu(s);
        // return solve(0, s);
    }
};