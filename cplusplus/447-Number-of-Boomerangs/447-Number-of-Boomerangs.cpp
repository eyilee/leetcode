#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfBoomerangs (vector<pair<int, int>>& points)
    {
        int sum = 0;
        for (auto& from : points) {
            unordered_map<int, int> edge;
            for (auto& to : points) {
                edge[get_distance (from, to)]++;
            }

            for (auto& it : edge) {
                sum += it.second * (it.second - 1);
            }
        }
        return sum;
    }

private:
    int get_distance (pair<int, int>& from, pair<int, int>& to)
    {
        return static_cast<int>(pow (to.first - from.first, 2) + pow (to.second - from.second, 2));
    }
};

int main ()
{
    vector<pair<int, int>> points {
        pair<int, int> (0, 0),
        pair<int, int> (1, 0),
        pair<int, int> (2, 0),
        pair<int, int> (3, 0)
    };

    Solution solution;
    cout << solution.numberOfBoomerangs (points) << endl;
}
