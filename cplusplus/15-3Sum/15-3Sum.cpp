#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum (vector<int>& nums)
    {
        sort (nums.begin (), nums.end ());

        size_t size = nums.size ();

        vector<vector<int>> ans;

        if (size < 3) {
            return ans;
        }

        for (size_t i = 0; i < size - 2; i++) {
            while (i > 0 && i < size - 2 && nums[i] == nums[i - 1]) {
                i++;
            }

            size_t j = i + 1;
            size_t k = size - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    ans.push_back (vector<int>{nums[i], nums[j], nums[k]});

                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};

int main ()
{
    Solution solution;
    vector<int> nums { 0, 0, 0 };
    //vector<int> nums{ -1, 0, 1, 2, -1, -4, 1, -2, 3, -3 };

    vector<vector<int>> ans = solution.threeSum (nums);

    for (auto& set : ans) {
        for (auto& it : set) {
            cout << it << ", ";
        }
        cout << endl;
    }
}
