#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers (int x, int y, int bound)
    {
        set<int> ans;
        for (int i = 1; i + 1 <= bound; i *= (x == 1) ? bound : x) {
            for (int j = 1; i + j <= bound; j *= (y == 1) ? bound : y) {
                ans.insert (i + j);
            }
        }

        return vector<int> (ans.begin (), ans.end ());
    }
};

int main ()
{
    Solution solution;

    vector<int> ans = solution.powerfulIntegers (1, 3, 10);

    for (auto& it : ans) {
        cout << it << endl;
    }

    return 0;
}
