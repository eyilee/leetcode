#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string removeKdigits (string num, int k)
    {
        string ans;

        for (auto& it : num) {
            while (ans.size () > 0 && it < ans.back () && k > 0) {
                ans.pop_back ();
                k--;
            }

            if (ans.size () > 0 || it != '0') {
                ans.push_back (it);
            }
        }

        while (ans.size () > 0 && k--) {
            ans.pop_back ();
        }

        return ans.empty () ? "0" : ans;
    }
};

int main ()
{
    Solution solution;
    cout << solution.removeKdigits ("102115352845", 2) << endl;
}
