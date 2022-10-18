#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    std::string says[31];

public:
    Solution ()
    {
        says[1] = "1";
    }

    string countAndSay (int n) {
        if (n <= 1) {
            return says[1];
        }

        if (!says[n].empty ()) {
            return says[n];
        }

        int next = n - 1;
        while (next > 0 && says[next].empty ()) {
            says[next] = countAndSay (next);
            next--;
        }

        std::string say = "";
        int value = 0;
        int count = 0;
        for (auto& c : says[n - 1]) {
            int v = c - 48;
            if (v == value) {
                count++;
                continue;
            }

            if (value == 0) {
                value = v;
                count = 1;
            }
            else {
                say.append (std::to_string (count));
                say.append (std::to_string (value));

                value = v;
                count = 1;
            }
        }
        say.append (std::to_string (count));
        say.append (std::to_string (value));
        says[n] = say;

        return say;
    }
};

int main ()
{
    Solution solution;
    for (int i = 1; i <= 30; i++) {
        cout << solution.countAndSay (i) << endl;
    }

    return 0;
}
