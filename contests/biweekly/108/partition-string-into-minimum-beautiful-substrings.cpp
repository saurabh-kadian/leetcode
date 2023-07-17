class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int index, int lastIndex, string& s, set<string>& powers){
        string sub = s.substr(lastIndex, index - lastIndex + 1);
        if(index == s.length() - 1){
            if(powers.find(sub) != powers.end())
                return 1;
            return 1e5;
        }
        
        stringstream ss;
        ss << index << "-" << lastIndex;
        string key = ss.str();
        
        if(cache.find(key) != cache.end())
            return cache[key];
        
        int answer = 1e5;
        if(powers.find(sub) != powers.end()){
            answer = min(answer, solve(index + 1, index + 1, s, powers) + 1);
        }
        answer = min(answer, solve(index + 1, lastIndex, s, powers));
        return cache[key] = answer;
    }
    int minimumBeautifulSubstrings(string s) {
        cache.clear();
        set<string> powers;
        int power = 1;
        int limit = powl(2, 16) + 1;
        while(power < limit){
            string p = bitset<24>(power).to_string();
            int clip = 0;
            while(p[clip] != '1' && clip < p.size()){
                clip++;
            }
            p = p.substr(clip, p.size() - clip + 1);
            powers.insert(p);
            power *= 5;
        }
        int answer = solve(0, 0, s, powers);
        return (answer >= 1e5 ? -1 : answer);
    }
};