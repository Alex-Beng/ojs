class Solution {
public:
    int maximum(int a, int b) {
        long long int diff = ((long long)a-(long long)b);
        long int mask = (diff>>31)&0xffffffff; // 全0 / 全1
        printf("%lx %lx", mask, ~mask);
        return mask & b | ~mask & a;
    };
};