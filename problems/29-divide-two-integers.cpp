// https://leetcode.com/problems/divide-two-integers/solutions/1516367/complete-thinking-process-intuitive-explanation-all-rules-followed-c-code/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = dividend;
        long b = divisor;
        // a = q*b + r
        if(a == b)   return 1;
        if(a == INT_MIN && b == -1) return INT_MAX;
        bool isSameSign = (a < 0 == b < 0);
        a = abs(a);
        b = abs(b);
        unsigned int number = 0;
        while(b <= a){
            int j = 0;
            while(a > (b<<(j+1))){
                j++;
            }
            // cout << a << " " << b << " " << j << endl;
            number += (1<<j);
            a -= (b<<j);
        }
        return isSameSign ? number : -number;
    }
};