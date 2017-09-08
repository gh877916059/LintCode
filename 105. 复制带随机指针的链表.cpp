class Solution 
{
public:
RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == NULL)
		return NULL;
	RandomListNode* result = NULL;
	RandomListNode* cur = head;
	RandomListNode* temp = NULL;
	while (cur != NULL)
	{
		temp = new RandomListNode(cur->label);
		temp->next = cur->next;
		temp->random = cur->random;
		cur->next = temp;
		cur = temp->next;
	}
	cur = head;
	while (cur != NULL)
	{
		temp = cur->next;
		if (temp->random != NULL)
			temp->random = temp->random->next;
		cur = temp->next;
	}
	result = head->next;
	cur = head;
	while (cur != NULL)
	{
		temp = cur->next;
		cur->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next = temp->next->next;
		}
		cur = cur->next;
	}
	return result;
}
};
