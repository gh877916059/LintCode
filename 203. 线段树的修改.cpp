class Solution 
{  
public:  
    void modify(SegmentTreeNode *root, int index, int value) 
    {  
        if(!root)  
            return ;  
        if(root->start==root->end)
        {  
            if(root->start==index)  
                root->max=value;  
            return ;  
        }  
        modify(root->left,index,value);  
        modify(root->right,index,value);  
        root->max=max(root->left->max,root->right->max);  
    }  
};  
