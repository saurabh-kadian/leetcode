class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<unsigned int> songs(60, 0);
        unsigned int answer = 0;
        for(int i = 0;i < time.size();++i)
            songs[time[i]%60]++;
        answer += max((unsigned int)0, 2*((songs[0]*(songs[0]-1))/2));
        for(int i = 1;i < 60;++i){
            if(i == 30){
                answer += max((unsigned int)0, 2*((songs[i]*(songs[i]-1))/2));
                continue;
            }
            answer += songs[i]*songs[60-i];
        }
        return (int)(answer / 2);
    }
};