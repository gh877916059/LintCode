class Solution 
{
public:
    void reorderList(ListNode *head) 
    {
	if (head == NULL)
		return;
	ListNode* cur = head;
	int length = 1;
	while (cur->next != NULL)
	{
		++length;
		cur = cur->next;
	}
	int shun, ni;
	if (length % 2 == 0)
	{
		shun = length / 2;
		ni = length / 2;
	}
	else
	{
		shun = length / 2 + 1;
		ni = length / 2;
	}
	ListNode* shun_begin=NULL;
	ListNode* shun_end=NULL;
	ListNode* ni_begin=NULL;
	ListNode* ni_end=NULL;
	cur=head;
	for(int i=0;i<shun;++i)
	{
	    if(shun_begin==NULL)
	    {
	        shun_begin=cur;
	        shun_end=cur;
	    }
	    else
	    {
	        shun_end->next=cur;
	        shun_end=shun_end->next;
	    }
	    cur=cur->next;
	}
	shun_end->next=NULL;
	for(int i=0;i<ni;++i)
	{
	    if(ni_begin==NULL)
	    {
	        ni_begin=cur;
	        ni_end=cur;
	    }
	    else
	    {
	        ni_end->next=cur;
	        ni_end=ni_end->next;
	    }
	    cur=cur->next;
	}
	if(ni>=1)
	    ni_end->next=NULL;
	if(ni>1)
	{
	    ListNode* per=ni_begin;
	    ListNode* cur2=ni_begin->next;
	    ListNode* next=NULL;
	    while(cur2!=NULL)
	    {
	        next=cur2->next;
	        cur2->next=per;
	        per=cur2;
	        cur2=next;
	    }
	    ni_begin->next=NULL;
	    ni_end=ni_begin;
	    ni_begin=per;
	}
	ListNode* result_begin = shun_begin;
	ListNode* result_end = shun_begin;
	shun_begin=shun_begin->next;
	for(int i=1;i<length;++i)
	{
	    if(i%2==0)
	    {
	        result_end->next=shun_begin;
	        shun_begin=shun_begin->next;
	    }
	    else
	    {
	        result_end->next=ni_begin;
	        ni_begin=ni_begin->next;
	    }
	    result_end=result_end->next;
	}
	result_end=NULL;
	head=result_begin;
	return;
    }
};


