class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;
        int n = rating.size();
        for(int j = 1; j < n-1; j++){
            int smaller_left = 0;
            int larger_left = 0;
            
            int smaller_right = 0;
            int larger_right = 0;

            int rating_j = rating[j];

            for(int i = 0; i < j; i++){
                if(rating[i] < rating_j) smaller_left++;
                else larger_left++;
            }
            for(int k = j+1; k < n; k++){
                if(rating[k] < rating_j) smaller_right++;
                else larger_right++;
            }
        
            total += smaller_left * larger_right + smaller_right * larger_left;
        }
        return total;
    }
};