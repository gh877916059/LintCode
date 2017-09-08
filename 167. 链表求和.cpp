class Solution
{
public:
	ListNode *addLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* xin_begin=NULL;
		ListNode* xin_end=NULL;
		int jin_wei = 0;
		int sum = 0;
		while (l1 != NULL&&l2 != NULL)
		{
			sum = l1->val + l2->val + jin_wei;
			if (xin_begin == NULL)
			{
				xin_begin = new ListNode(sum % 10);
				xin_end = xin_begin;
			}
			else
			{
				xin_end->next = new ListNode(sum % 10);
				xin_end = xin_end->next;
			}
			l1 = l1->next;
			l2 = l2->next;
			jin_wei = sum / 10;
		}
		while (l1 != NULL)
		{
			sum = l1->val + jin_wei;
			xin_end->next = new ListNode(sum % 10);
			xin_end = xin_end->next;
			l1 = l1->next;
			jin_wei = sum / 10;
		}
		while (l2 != NULL)
		{
			sum = l2->val + jin_wei;
			xin_end->next = new ListNode(sum % 10);
			xin_end = xin_end->next;
			l2 = l2->next;
			jin_wei = sum / 10;
		}
		if(jin_wei>0)
		{
		    xin_end->next=new ListNode(jin_wei);
		}
		return xin_begin;
	}
};
