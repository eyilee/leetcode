#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSwapsCouples (vector<int>& row)
    {
        int swap_times = 0;

        size_t length = row.size ();
        for (size_t i = 0; i < length; i += 2) {
            int couple = get_couple (row[i]);

            if (couple != row[i + 1]) {
                search_and_swap_couple (row, i + 1, couple);
                swap_times++;
            }
        }

        return swap_times;
    }

    int get_couple (const int lhs)
    {
        return lhs % 2 == 0 ? lhs + 1 : lhs - 1;
    }

    void search_and_swap_couple (vector<int>& row, const size_t index, const int couple)
    {
        vector<int>::iterator it;
        it = find (row.begin (), row.end (), couple);

        *it = row[index];
        row[index] = couple;
    }
};

int main ()
{
    vector<int> row { 0, 3, 2, 6, 1, 4, 7, 5 };

    Solution solution;
    cout << solution.minSwapsCouples (row) << endl;
}
