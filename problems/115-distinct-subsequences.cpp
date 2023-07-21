class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, string& s, string& t){
        if(i == s.size())
            return (j == t.size());
        if(j == t.size())
            return 1;

        stringstream ss;
        ss << i << "-" << j << endl;
        string key = ss.str();
        if(cache.find(key) != cache.end())
            return cache[key];
        
        int answer = solve(i + 1, j, s, t);
        if(s[i] == t[j])
            answer += solve(i + 1, j + 1, s, t);
        return cache[key] = answer;
    }
    int numDistinct(string s, string t) {
        return solve(0, 0, s, t);
    }
};