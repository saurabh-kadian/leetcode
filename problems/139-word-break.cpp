class Solution {
public:
    bool match(int& index, string& s, string& p){
        if(p.size() > s.size() - index)
            return false;
        for(int i = 0;i < p.size();++i)
            if(s[index+i] != p[i])
                return false;
        return true;
    }
    unordered_map<int, bool> cache;
    bool solve(int index, string& s, unordered_map<char, vector<string> >& mapping){
        if(index == s.size())
            return true;

        if(cache.find(index) != cache.end())
            return cache[index];
        
        bool answer = false;
        for(int i = 0;i < mapping[s[index]].size();++i){
            if(match(index, s, mapping[s[index]][i])){
                answer |= solve(index + mapping[s[index]][i].size(), s, mapping);
            }
        }
        return cache[index] = answer;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        cache.clear();
        unordered_map<char, vector<string> > mapping;
        for(int i = 0;i < wordDict.size();++i)
            mapping[wordDict[i][0]].push_back(wordDict[i]);
        return solve(0, s, mapping);
    }
};