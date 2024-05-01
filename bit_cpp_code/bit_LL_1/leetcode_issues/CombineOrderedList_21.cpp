struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* new_list=nullptr;
        while(head1)
        {
            ListNode* record=nullptr;
            while(head2)
        {
            
            if(head2->val < head1->val)
            {
                record = head2;
                break;
            }
            head2=head2->next;
        }
        
        if(record==nullptr)
           Pushback(new_list,head1);
        else
            Pushback(new_list,record);
        head1=head1->next;
        }


        return new_list;
    }


    void Pushback(ListNode& head, ListNode& data)
    {
        if(head == nullptr)
        {
            head=data;
        }
        else
        {
            ListNode* temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=data;
        }
    }
};
