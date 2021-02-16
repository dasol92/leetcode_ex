// Problem from https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode *p1 = l1, *p2 = l2, *output = head;
		int carry = 0;
		while(p1 != nullptr || p2 != nullptr) {
			int val1 = (p1 != nullptr) ? p1->val : 0;
			int val2 = (p2 != nullptr) ? p2->val : 0;
			int sum = val1 + val2 + carry;
			carry = sum / 10;
			output->next = new ListNode(sum % 10);
			output = output->next;

			p1 = (p1 != nullptr) ? p1->next : nullptr;
			p2 = (p2 != nullptr) ? p2->next : nullptr;
		}
		if (carry == 1) {
			output->next = new ListNode(carry);
		}
		return head->next;
	}
};