#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> numberOfLines (vector<int>& widths, string S)
    {
        int lines = 1;
        int currentline = 0;

        for (auto& it : S) {
            currentline += widths[it - 'a'];

            if (currentline > 100) {
                lines++;
                currentline = widths[it - 'a'];
            }
        }

        return vector<int>{lines, currentline};
    }
};

int main ()
{
    vector<int> widths { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10 };
    string S = "bbbcccdddaaa";

    Solution solution;
    vector<int> ans = solution.numberOfLines (widths, S);
    for (auto& it : ans) {
        cout << it << endl;
    }
}
