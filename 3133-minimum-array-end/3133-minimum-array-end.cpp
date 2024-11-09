class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;
        for(long long mask = 1; x || n; mask = mask << 1) {
            if(x & 1) {
                x = x >> 1;
                continue;
            }
            x = x >> 1;
            if(n & 1)
                ans ^= mask;
            n = n >> 1;
        }
        return ans;
    }
};