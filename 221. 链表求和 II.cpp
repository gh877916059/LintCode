#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

/*
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution 
{
public:
	ListNode * addLists2(ListNode * l1, ListNode * l2) 
	{
		auto head_1 = reverse(l1, NULL);
		auto head_2 = reverse(l2, NULL);
		int val = 0;
		ListNode * head = NULL;
		ListNode * tail = NULL;
		while (head_1 != NULL || head_2 != NULL)
		{
			if (head_1 != NULL)
			{
				val += head_1->val;
				head_1 = head_1->next;
			}
			if (head_2 != NULL)
			{
				val += head_2->val;
				head_2 = head_2->next;
			}
			if (head == NULL)
			{
				head = new ListNode(val % 10);
				tail = head;
			}
			else
			{
				tail->next = new ListNode(val % 10);
				tail = tail->next;
			}
			val /= 10;
		}
		while (val > 0)
		{
			tail->next = new ListNode(val % 10);
			tail = tail->next;
			val /= 10;
		}
		return reverse(head, NULL);
	}
	ListNode* reverse(ListNode* head, ListNode* tail)
	{
		ListNode *pre = tail;
		while (head != tail)
		{
			ListNode *t = head->next;
			head->next = pre;
			pre = head;
			head = t;
		}
		return pre;
	}
};
