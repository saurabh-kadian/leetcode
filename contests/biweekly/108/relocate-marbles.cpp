class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, int> positions;
        for(int i = 0;i < nums.size();++i){
            positions[nums[i]]++;
        }
        
        for(int i = 0;i < moveFrom.size();++i){
            if(positions.find(moveFrom[i]) == positions.end())
                continue;
            if(moveFrom[i] == moveTo[i])
                continue;
            positions[moveTo[i]] += positions[moveFrom[i]];
            positions[moveFrom[i]] = 0;
        }
        vector<int> answer;
        for(auto it: positions){
            if(it.second != 0){
                answer.push_back(it.first);
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};