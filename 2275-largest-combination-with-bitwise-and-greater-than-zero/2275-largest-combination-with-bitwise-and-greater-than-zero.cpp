class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int counter[24] = {};
        
        for(int candidate : candidates) {
            int i = 0;
            while(candidate) {
                i++;
                if(candidate % 2 == 1)
                    counter[24-i]++;
                candidate = candidate >> 1;
            }
        }
        int max = 0;
        for(int c : counter) {
            max = c > max ? c : max;
        }
        return max;
    }
};