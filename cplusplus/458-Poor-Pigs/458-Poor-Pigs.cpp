#include <iostream>

using namespace std;

class Solution
{
public:
    int poorPigs (int buckets, int minutesToDie, int minutesToTest)
    {
        if (buckets == 1) {
            return 0;
        }

        int times = minutesToTest / minutesToDie + 1;

        int n = 1;
        while (pow (times, n) < buckets) {
            n++;
        }

        return n;
    }
};

int main ()
{
    Solution solution;
    cout << solution.poorPigs (1000, 15, 60) << endl;
}
