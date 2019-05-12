#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	char letters[26];

public:
	Solution() {
		for (size_t i = 0; i < 26; i++) {
			letters[i] = 'a' + i;
		}
	}

	vector<string> commonChars(vector<string>& A) {
		map<char, int> common;
		for (auto &x : A) {
			map<char, int> count;
			for (auto &c : x) {
				count[c] += 1;
			}

			for (auto &c : letters) {
				if (common.find(c) != common.end()) {
					if (common[c] > count[c]) {
						common[c] = count[c];
					}
				}
				else {
					common[c] = count[c];
				}
			}
		}

		vector<string> ans;
		for (auto &x : common) {
			if (x.second > 0) {
				for (size_t i = 0; i < x.second; i++) {
					ans.push_back(string(1, x.first));
				}
			}
		}

		return ans;
	}
};

int main()
{
	Solution solution;

	vector<string> A = { "bella","label","roller" };

	vector<string> ans = solution.commonChars(A);

	for (auto &x : ans) {
		cout << x << endl;
	}

	return 0;
}
