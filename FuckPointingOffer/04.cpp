#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows==0) {
            return false;
        }
        int cols = matrix[0].size();
        
        int curr_row = 0;
        int curr_col = cols-1;

        while (curr_col>=0 && curr_row<rows) {
            int curr = matrix[curr_row][curr_col];
            if (curr > target) {
                curr_col--;
            }
            else if (curr < target) {
                curr_row++;
            }
            else {
                return true;
            }
        }
        return false;
    }

};