#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement (vector<int>& findNums, vector<int>& nums)
    {
        vector<int> ans;

        for (auto& left : findNums) {
            auto right = find (nums.begin (), nums.end (), left);

            while (right != nums.end ()) {
                if (*right > left) {
                    ans.push_back (*right);
                    break;
                }

                right++;
            }

            if (right == nums.end ()) {
                ans.push_back (-1);
            }
        }

        return ans;
    }
};

int main ()
{
    Solution solution;
    vector<int> num1 { 4, 1, 2 };
    vector<int> num2 { 1, 3, 4, 2 };
    vector<int> ans = solution.nextGreaterElement (num1, num2);

    for (auto& it : ans) {
        cout << it << endl;
    }
}
