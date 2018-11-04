#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int superEggDrop(int K, int N) {
		vector<int> dp(K + 1, 0);

		int step = 0;
		for (; dp[K] < N; step++) {
			for (int i = K; i > 0; i--) {
				dp[i] = 1 + dp[i] + dp[i - 1];
			}
		}

		return step;
	}
};

int main()
{
	// 2 4 > 2
	Solution solution;
	solution.superEggDrop(3, 8);
}
