class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, 
                int j, 
                string& first, 
                string& second, 
                vector<int>& prefixFirst,
                vector<int>& prefixSecond){
        if(i == first.size())
            return prefixSecond[second.size()]-prefixSecond[j];
        if(j == second.size())
            return prefixFirst[first.size()]-prefixFirst[i];

        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();

        if(cache.find(key) != cache.end())
            return cache[key];

        int answer = 1e9;
        if(first[i] == second[j]){
            // if match?
            answer = min(answer, solve(i + 1, j + 1, first, second, prefixFirst, prefixSecond));
        } else {
            // delete from first
            answer = min(answer, solve(i + 1, j, first, second, prefixFirst, prefixSecond) + (int)first[i]);
            // delete from second
            answer = min(answer, solve(i, j + 1, first, second, prefixFirst, prefixSecond) + (int)second[j]);
        }
        return cache[key] = answer;
    }
    int bottomUp(string first, string second, vector<int> prefixFirst, vector<int> prefixSecond){
        vector<vector<int> > dp(first.size() + 2, vector<int>(second.size() + 2, 1e9));
        for(int i = first.size();i >= 0;--i){
            for(int j = second.size();j >= 0;--j){
                if(i == first.size()){
                    dp[i][j] = prefixSecond[second.size()] - prefixSecond[j];
                    continue;
                }
                if(j == second.size()){
                    dp[i][j] = prefixFirst[first.size()] - prefixFirst[i];
                    continue;
                }
                if(first[i] == second[j]){
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
                } else {
                    dp[i][j] = min(dp[i][j], min(dp[i+1][j] + (int)first[i],
                                                 dp[i][j+1] + (int)second[j]));
                }
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<int> prefixFirst(s1.size()+2, 0);
        vector<int> prefixSecond(s2.size()+2, 0);
        for(int i = 0;i < s1.size();++i){
            prefixFirst[i+1] = prefixFirst[i]+(int)s1[i];
        }
        for(int i = 0;i < s2.size();++i){
            prefixSecond[i+1] = prefixSecond[i]+(int)s2[i];
        }
        return bottomUp(s1, s2, prefixFirst, prefixSecond);
        // return solve(0, 0, s1, s2, prefixFirst, prefixSecond);
    }
};