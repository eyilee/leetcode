#include <iostream>
#include <locale>
#include <string>

using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (auto& it : str) {
			it = tolower(it);
		}
		return str;
	}
};

int main()
{
	Solution solution;
	cout << solution.toLowerCase("Hello World!") << endl;
}
