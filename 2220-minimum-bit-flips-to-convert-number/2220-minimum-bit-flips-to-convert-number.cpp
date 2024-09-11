class Solution {
public:
    int minBitFlips(int start, int goal) {
        start ^= goal;
        int count = 0;
        while(start){
            count += start % 2;
            start >>= 1;
        }
        return count;
    }
};