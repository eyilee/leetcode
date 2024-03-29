#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int superEggDrop (int K, int N)
    {
        vector<int> dp (K + 1, 0);

        int step = 0;
        while (dp[K] < N) {
            for (int i = K; i > 0; i--) {
                dp[i] += dp[i - 1] + 1;
            }

            step++;
        }

        return step;
    }
};

int main ()
{
    Solution solution;
    cout << solution.superEggDrop (3, 8) << endl;
}
