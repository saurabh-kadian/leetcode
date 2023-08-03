class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitCount = __builtin_popcount(num2);
        int answer = 0;
        for(int i = 31;bitCount > 0 && i >= 0;--i){
            if(((num1>>i)&1) == 1){
                bitCount--;
                answer |= (1<<i);
            }
        }
        if(bitCount > 0){
            for(int i = 0;bitCount > 0 && i < 32;++i){
                if(((num1>>i)&1) == 0){
                    bitCount--;
                    answer |= (1 << i);
                }
            }
        }
        return answer;
    }
};