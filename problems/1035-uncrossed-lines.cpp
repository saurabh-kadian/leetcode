class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, vector<int>& s, vector<int>& t){
        if(i == s.size() || j == t.size())
            return 0;
        
        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];
        
        if(s[i] == t[j])
            return cache[key] = solve(i + 1, j + 1, s, t) + 1;
        return cache[key] = max(solve(i + 1, j, s, t), solve(i, j + 1, s, t));
    }
    int bottomUp(vector<int>& s, vector<int>& t){
        vector<vector<int> > dp(s.size() + 2, vector<int>(t.size() + 2, 0));
        for(int i = s.size() - 1;i >= 0;--i){
            for(int j = t.size() - 1;j >= 0;--j){
                if(s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return bottomUp(nums1, nums2);
        // return solve(0, 0, nums1, nums2);
    }
};