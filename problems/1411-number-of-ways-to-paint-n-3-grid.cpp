class Solution {
public:
    int mod = 1e9 + 7;
    int N = -1;
    // answer, (same, not same)
    pair<long long, pair<long long, long long>> solve(int row){
        if(row == N){
            return make_pair(12, make_pair(6LL, 6LL));
        }
        pair<long long, pair<long long, long long>> answer = solve(row + 1);
        long long firstVal = ((answer.second.first%mod * 5LL%mod)%mod + (answer.second.second%mod * 4LL%mod)%mod)%mod;
        return make_pair(firstVal, make_pair((answer.second.first * 3 + answer.second.second * 2)%mod,
                                             (answer.second.first * 2 + answer.second.second * 2)%mod));
    }
    int numOfWays(int n) {
        N = n;
        return int(solve(1).first%mod);
    }
};