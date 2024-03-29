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

        size_t length = str.length ();
        for (size_t i = 1; i <= length; i++) {
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
        size_t length = str.length ();
        if (length == 0) {
            return true;
        }

        size_t head = 0;
        size_t tail = length - 1;

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
