#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {

		find_partition(s);

		return partitions;
	}

private:
	vector<vector<string>> partitions;
	vector<string> current_partition;

	void find_partition(string str) {
		if (str.empty()) {
			partitions.push_back(current_partition);
			return;
		}

		for (int i = 1; i <= str.length(); i++)
		{
			string sub = str.substr(0, i);
			if (isPalindrome(sub)) {
				current_partition.push_back(sub);

				find_partition(str.substr(i, str.length() - i));

				current_partition.pop_back();
			}
		}
	}

	bool isPalindrome(string str) {
		string res;
		res.resize(str.size());
		reverse_copy(str.begin(), str.end(), res.begin());

		return str == res;
	}
};

int main()
{
	Solution solution;
	solution.partition("aaabaa");
}
