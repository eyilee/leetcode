#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap (vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int length = img1.size ();

        std::vector<unsigned int> rows1;
        std::vector<unsigned int> rows2;
        rows1.resize (length);
        rows2.resize (length);

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                rows1[i] |= img1[i][j] << length - j - 1;
                rows2[i] |= img2[i][j] << length - j - 1;
            }
        }

        int mask = 0;
        for (int i = 0; i < length; i++) {
            mask |= 1 << i;
        }

        int max = 0;
        for (int i = 1 - length; i < length; i++) {
            for (int j = 1 - length; j < length; j++) {
                int total = 0;

                if (i >= 0 && j >= 0) {
                    for (int k = 0; k < length - i; k++) {
                        unsigned int value = (rows1[k] >> j) & rows2[k + i] & mask;
                        while (value > 0) {
                            total += value & 1;
                            value = value >> 1;
                        }
                    }
                }
                else if (i < 0 && j >= 0) {
                    for (int k = 0; k < length + i; k++) {
                        unsigned int value = (rows1[k - i] >> j) & rows2[k] & mask;
                        while (value > 0) {
                            total += value & 1;
                            value = value >> 1;
                        }
                    }
                }
                else if (i >= 0 && j < 0) {
                    for (int k = 0; k < length - i; k++) {
                        unsigned int value = (rows1[k] << -j) & rows2[k + i] & mask;
                        while (value > 0) {
                            total += value & 1;
                            value = value >> 1;
                        }
                    }
                }
                else if (i < 0 && j < 0) {
                    for (int k = 0; k < length + i; k++) {
                        unsigned int value = (rows1[k - i] << -j) & rows2[k] & mask;
                        while (value > 0) {
                            total += value & 1;
                            value = value >> 1;
                        }
                    }
                }

                if (total > max) {
                    max = total;
                }
            }
        }
        return max;
    }
};

int main ()
{
    vector<vector<int>> img1 = { { 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
    vector<vector<int>> img2 = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 } };
  

    Solution solution;
    cout << solution.largestOverlap (img1, img2) << endl;

    return 0;
}
