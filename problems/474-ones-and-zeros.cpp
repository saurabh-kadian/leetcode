class Solution {
public:
    unordered_map<string, int> cache;
    int cacheArr[602][102][102];
    int solve(int index, int zero, int one, vector<pair<int, int> >& counts){
        if(index == counts.size())
            return (zero >= 0 && one >= 0 ? 0 : -1e4);
        if(zero < 0 || one < 0)
            return -1e4;

        stringstream ss;
        ss << index << "-" << zero << "-" << one;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];
        
        return cache[key] = max(solve(index + 1, zero, one, counts),
                                solve(index + 1, zero-counts[index].first, one-counts[index].second, counts) + 1);
    }
    int bottomUp(vector<pair<int, int> >& counts, int& zeros, int& ones){
        vector<vector<int> > dp(zeros + 2, vector<int>(ones + 2, -1e4));
        for(int i = counts.size();i >= 0;--i){
            vector<vector<int> > temp(zeros + 2, vector<int>(ones + 2, -1e4));
            for(int m = 0;m <= zeros;++m){
                for(int n = 0;n <= ones;++n){
                    if(i == counts.size()){
                        temp[m][n] = 0;
                        continue;
                    }
                    if(m-counts[i].first < 0 || n-counts[i].second < 0){
                        temp[m][n] = dp[m][n];
                        continue;
                    }
                    temp[m][n] = max(dp[m][n], dp[m-counts[i].first][n-counts[i].second] + 1);
                }
            }
            dp = temp;
        }
        return dp[zeros][ones];
    }
    int solveArr(int index, int zero, int one, vector<pair<int, int> >& counts){
        if(index == counts.size())
            return (zero >= 0 && one >= 0 ? 0 : -1e4);
        if(zero < 0 || one < 0)
            return -1e4;

        if(cacheArr[index][zero][one] >= 0)
            return cacheArr[index][zero][one];
        
        return cacheArr[index][zero][one] = 
                            max(solve(index + 1, zero, one, counts),
                                solve(index + 1, zero-counts[index].first, one-counts[index].second, counts) + 1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int> > counts(strs.size());
        for(int i = 0;i < strs.size();++i){
            int zero = 0;
            int one = 0;
            for(int j = 0;j < strs[i].size();++j){
                strs[i][j] == '0' ? zero++ : one++;
            }
            counts[i] = make_pair(zero, one);
        }
        memset(&cacheArr[0][0][0], -1e4, sizeof(cacheArr));
        return solveArr(0, m, n, counts); // TLE on last test case
        // return bottomUp(counts, m, n); // AC
        // return solve(0, m, n, counts); // TLE
    }
};