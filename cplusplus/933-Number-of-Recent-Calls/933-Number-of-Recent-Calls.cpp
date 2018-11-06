#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
	int ping(int t) {
		pings.push(t);

		int range = t < 3000 ? 0 : t - 3000;

		while (pings.front() < range) {
			pings.pop();
		}

		return pings.size();
	}
private:
	queue<int> pings;
};

int main()
{
	RecentCounter recent_counter;
	cout << recent_counter.ping(0) << endl;
	cout << recent_counter.ping(1) << endl;
	cout << recent_counter.ping(3000) << endl;
	cout << recent_counter.ping(3001) << endl;
	cout << recent_counter.ping(3002) << endl;
}
