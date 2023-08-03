class Solution {
public:
    int reducedCode(vector<int>& nums){
        int answer = 0;
        for(int i = 0;i < 32;++i){
            int bitSum = 0;
            for(int index = 0;index < nums.size();++index){
                if(((nums[index]>>i)&1) == 1){
                    bitSum++;
                }
            }
            answer |= (bitSum%3) << i;
        }
        return answer;
    }
    int singleNumber(vector<int>& nums) {
        return reducedCode(nums);
    }
}

///////////////////////////////////////////////// DETAILED /////////////////////////////////////////////////

class Solution {
public:
    string convertToBits(long x){
        string bits = "";
        while(x != 0){
            bits += (x%2) + '0';
            x /= 2;
        }
        return bits;
    }
    long convertBitsToDecimal(string bits){
        long answer = 0;
        for(int i = 0;i < bits.size();++i)
            answer = 2*answer + (bits[i] - '0');
        return answer;
    }
    int singleNumber(vector<int>& nums) {
        vector<int> posiFreq(64, 0);
        vector<int> negiFreq(64, 0);
        for(int i = 0;i < nums.size();++i){
            if(nums[i] < 0){
                string bits = convertToBits(-1*(long)nums[i]);
                for(int j = 0;j < bits.size();++j){
                    negiFreq[j] += (bits[j] - '0');
                }    
                continue;
            }
            string bits = convertToBits((long)nums[i]);
            for(int j = 0;j < bits.size();++j){
                posiFreq[j] += (bits[j] - '0');
            }
        }
        string posiAnswer = "";
        for(int i = 0;i < posiFreq.size();++i){
            posiAnswer += (posiFreq[i]%3) + '0';
        }
        string negiAnswer = "";
        for(int i = 0;i < negiFreq.size();++i){
            negiAnswer += (negiFreq[i]%3) + '0';
        }
        reverse(negiAnswer.begin(), negiAnswer.end());
        reverse(posiAnswer.begin(), posiAnswer.end());
        long n = convertBitsToDecimal(negiAnswer);
        long p = convertBitsToDecimal(posiAnswer);
        if(n > 0)
            return -n;
        if(p > 0)
            return p;
        return 0;
    }
};