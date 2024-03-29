#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingDistance (int x, int y)
    {
        int mask = x ^ y;

        int sum = 0;
        for (int i = 0; i < 32; i++) {
            sum += mask & 1;
            mask = mask >> 1;
        }

        return sum;
    }
};

int main ()
{
    Solution solution;
    cout << solution.hammingDistance (1, 6) << endl;
}
