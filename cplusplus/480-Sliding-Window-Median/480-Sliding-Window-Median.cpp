#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<double> medianSlidingWindow (vector<int>& nums, int k)
    {
        multiset<int> window (nums.begin (), nums.begin () + k);
        auto mid = next (window.begin (), k / 2);

        vector<double> medians;
        for (int i = k; ; i++) {
            medians.push_back (((double)(*mid) + *prev (mid, 1 - k % 2)) / 2);

            if (i == nums.size ()) {
                return medians;
            }

            window.insert (nums[i]);
            if (nums[i] < *mid) {
                mid--;
            }

            if (nums[i - k] <= *mid) {
                mid++;
            }
            window.erase (window.lower_bound (nums[i - k]));
        }
    }
};

int main ()
{
    Solution solution;
    //int k = 3;
    //vector<int> nums = { 1, 3, -1 ,-3, 5, 3, 6, 7 };
    //vector<double> ans = solution.medianSlidingWindow(nums, k);

    int k = 2;
    vector<int> nums = { 2147483647, 2147483647 };
    vector<double> ans = solution.medianSlidingWindow (nums, k);

    for (auto& it : ans) {
        cout << it << endl;
    }

    return 0;
}
