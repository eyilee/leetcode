#include <iostream>
#include <vector>

using namespace std;

enum State
{
    OneBit, FirstOfTwoBit, SecondOfTwoBit
};

class Solution
{
public:
    bool isOneBitCharacter (vector<int>& bits)
    {
        State state = State::OneBit;

        for (auto& bit : bits) {
            switch (state) {
            case OneBit:
                state = bit == 0 ? State::OneBit : State::FirstOfTwoBit;
                break;
            case FirstOfTwoBit:
                state = State::SecondOfTwoBit;
                break;
            case SecondOfTwoBit:
                state = bit == 0 ? State::OneBit : State::FirstOfTwoBit;
                break;
            default:
                break;
            }
        }

        return state == State::OneBit;
    }
};

int main ()
{
    vector<int> bits { 1, 1, 1, 0 };

    Solution solution;
    cout << solution.isOneBitCharacter (bits) << endl;
}
