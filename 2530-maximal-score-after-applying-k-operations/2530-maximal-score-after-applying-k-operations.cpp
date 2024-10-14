class Solution {
    public:
    long long maxKelements(vector<int>& nums, int k) {
        double score = 0;
        
        std::make_heap(nums.begin(), nums.end());
        for(int i = 0; i<k; i++)
        {
            double num = nums.front();
            score += num;

            std::pop_heap(nums.begin(), nums.end());
            nums.pop_back();


            nums.push_back(ceil((long double)num/3));
            std::push_heap(nums.begin(), nums.end());
        }
        return score;
    }
};