 class Solution 
 {  
public:  
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) 
    {  
        int size=hashTable.size();  
        int Newsize=2*size;  
        vector<ListNode*> res(Newsize,NULL);  
        if(size==0)  return res;  
        for(int i=0;i<size;i++)  
        {  
            ListNode* cur=hashTable[i];  
            while(cur!=NULL)  
            {  
                ListNode* temp=cur;  
                cur=cur->next;  
                int index=(temp->val%Newsize+Newsize)%Newsize;  
                if(res[index]==NULL)  
                {  
                    res[index]=temp;  
                    temp->next=NULL;  
                }  
                else  
                {  
                    ListNode* p=res[index];  
                    while(p->next!=NULL)  p=p->next;  
                    p->next=temp;  
                    temp->next=NULL;  
                }  
            }  
        }  
        return res;  
    }  
};  
