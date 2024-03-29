#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isInterleave (string s1, string s2, string s3)
    {
        auto s1_size = s1.size ();
        auto s2_size = s2.size ();

        if (s1_size + s2_size != s3.size ()) {
            return false;
        }

        vector<vector<bool>> dp (s1_size + 1, vector<bool> (s2_size + 1, false));

        for (int i = 0; i <= s1_size; i++) {
            for (int j = 0; j <= s2_size; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];
                }
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                }
                else {
                    dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
                }
            }
        }

        return dp[s1_size][s2_size];
    }
};

int main ()
{
    Solution solution;
    cout << solution.isInterleave ("aabcc", "dbbca", "aadbbbaccc") << endl;
}
