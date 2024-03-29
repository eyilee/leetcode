#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxIncreaseKeepingSkyline (vector<vector<int>>& grid)
    {
        size_t row_size = grid.size ();
        size_t col_size = grid[0].size ();

        vector<int> row_max (row_size);
        vector<int> col_max (col_size);

        // find max value each row and col
        for (size_t i = 0; i < row_size; i++) {

            row_max[i] = *max_element (grid[i].begin (), grid[i].end ());

            for (int j = 0; j < col_size; j++) {
                col_max[j] = max (col_max[j], grid[i][j]);
            }
        }

        int sum = 0;

        for (size_t i = 0; i < row_size; i++) {
            for (size_t j = 0; j < col_size; j++) {
                sum += min (row_max[i], col_max[j]) - grid[i][j];
            }
        }

        return sum;
    }
};

int main ()
{
    vector<vector<int>> grid {
        { 3, 0, 8, 4, 1 },
        { 2, 4, 5, 7, 3 },
        { 9, 2, 6, 3, 5 },
        { 0, 3, 1, 0, 1 }
    };

    Solution solution;
    cout << solution.maxIncreaseKeepingSkyline (grid) << endl;
}
