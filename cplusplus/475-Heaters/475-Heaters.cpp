#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findRadius (vector<int>& houses, vector<int>& heaters)
    {
        sort (heaters.begin (), heaters.end ());

        vector<int> radius;
        for (vector<int>::iterator it = houses.begin (); it != houses.end (); it++) {
            vector<int>::iterator lower = lower_bound (heaters.begin (), heaters.end (), *it);

            if (lower == heaters.begin ()) {
                radius.push_back (abs (*it - *lower));
            }
            else if (lower == heaters.end ()) {
                radius.push_back (abs (*it - *prev (lower)));
            }
            else {
                radius.push_back (min (abs (*it - *lower), abs (*it - *prev (lower))));
            }
        }

        return *max_element (radius.begin (), radius.end ());
    }
};

int main ()
{
    vector<int> houses = { 1, 2, 3, 7, 8, 99 };
    vector<int> heaters = { 2, 8 };

    Solution solution;
    cout << solution.findRadius (houses, heaters) << endl;
}
