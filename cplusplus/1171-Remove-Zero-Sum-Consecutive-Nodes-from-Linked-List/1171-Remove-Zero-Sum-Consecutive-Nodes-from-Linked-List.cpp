#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode (int x)
		: val (x)
		, next (nullptr)
	{
	}
};

class Solution
{
public:
	ListNode* removeZeroSumSublists (ListNode* head)
	{
		ListNode* dummy = new ListNode (0);
		dummy->next = head;

		ListNode* prev = dummy;
		ListNode* current = head;
		while (current != nullptr) {
			while (current != nullptr && current->val == 0) {
				current = current->next;
				// delete prev->next;
				prev->next = current;
			}

			if (current == nullptr) {
				break;
			}

			int sum = current->val;
			ListNode* next = current->next;
			while (next != nullptr) {
				sum += next->val;
				next = next->next;

				if (sum == 0) {
					while (current != next) {
						current = current->next;
						// delete prev->next;
						prev->next = current;
					}
				}
			}

			if (prev != nullptr) {
				prev = prev->next;
			}
			if (current != nullptr) {
				current = current->next;
			}
		}

		return dummy->next;
	}
};

int main ()
{
	Solution solution;

	int nums[4] = { 2, -3, 3, 1 };

	ListNode* head = new ListNode (1);
	ListNode* current = head;

	for (auto& val : nums) {
		current->next = new ListNode (val);
		current = current->next;
	}

	current = solution.removeZeroSumSublists (head);

	while (current != nullptr) {
		std::cout << current->val << std::endl;
		current = current->next;
	}

	return 0;
}
