class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> out;
        if (m*n != original.size())
            return out;
            
        auto it = original.begin();
        for(int i = 0; i < m; i++){
            vector<int> row;
            for(int j = 0; j < n; j++){
                row.push_back(*it);
                it++;
            }
            out.push_back(row);
        }
        return out;
    }
};