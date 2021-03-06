#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string>> partition (string s)
	{

		find_partition (s);

		return partitions;
	}

private:
	vector<vector<string>> partitions;
	vector<string> current_partition;

	void find_partition (string str)
	{
		if (str.empty ()) {
			partitions.push_back (current_partition);
			return;
		}

		int length = str.length ();
		for (int i = 1; i <= length; i++) {
			string sub = str.substr (0, i);
			if (isPalindrome (sub)) {
				current_partition.push_back (sub);

				find_partition (str.substr (i, str.length () - i));

				current_partition.pop_back ();
			}
		}
	}

	bool isPalindrome (string str)
	{
		int head = 0;
		int tail = str.length () - 1;

		while (head < tail) {
			if (str[head] != str[tail]) {
				return false;
			}

			head++;
			tail--;
		}

		return true;
	}
};

int main ()
{
	Solution solution;
	solution.partition ("aaabaa");
}
