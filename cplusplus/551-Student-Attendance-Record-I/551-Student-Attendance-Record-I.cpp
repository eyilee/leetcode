#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool checkRecord (string s)
    {
        int a = 0;
        int l = 0;

        for (auto& it : s) {
            switch (it) {
            case 'A':
                a++;
                l = 0;
                break;
            case 'L':
                l++;
                break;
            default:
                l = 0;
                break;
            }

            if (a > 1 || l > 2) {
                return false;
            }
        }

        return true;
    }
};

int main ()
{
    Solution solution;
    cout << solution.checkRecord ("PPALLP") << endl;
}
