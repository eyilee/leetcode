#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits (int N)
    {
        vector<int> num;

        for (int i = N; i != 0; i /= 10) {
            num.push_back (i % 10);
        }

        int ans = num[0];
        int max = num[0];
        size_t length = num.size ();
        for (size_t i = 1; i < length; i++) {
            if (num[i] <= num[i - 1] && num[i] <= max) {
                ans += num[i] * static_cast<int>(pow (10, i));
            }
            else {
                ans = num[i] * static_cast<int>(pow (10, i)) - 1;
                max = num[i] - 1;
            }
        }

        return ans;
    }
};

int main ()
{
    Solution solution;
    cout << solution.monotoneIncreasingDigits (21348) << endl;
}
