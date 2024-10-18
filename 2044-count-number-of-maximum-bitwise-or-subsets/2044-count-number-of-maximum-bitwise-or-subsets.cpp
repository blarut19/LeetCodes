class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int result = 0;
        int maxCount = 0;
        for(int num : nums)
        {
            maxCount = maxCount | num;
        }
        for(unsigned int i = 1; i < pow(2, nums.size()); i++)
        {
            int r = 0;
            for (unsigned int index = 0; index < nums.size(); index++)
            {
                if (i & (1 << index))
                {
                    r = r | nums[index];
                }
            }
            if(r == maxCount)
                result++;
        }
        return result;
    }
};