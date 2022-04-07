/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//Using extra space(map)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        while(temp)
        {
            mp[temp]->next= mp[temp->next];
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
    }
};


//Without using extra space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* x= new Node(temp->val);
            x->next=temp->next;
            temp->next=x;
            temp=x->next;
        }
        temp=head;
        
        Node* newlist=temp->next;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                newlist->random=temp->random->next;
            }
            temp=newlist->next;
            if(temp!=NULL)
            {
                newlist=temp->next;
            }
        }
        
        temp = head;
        newlist=temp->next;
        Node* ans=temp->next;
        while(temp!=NULL)
        {
            temp->next=newlist->next;
            temp=temp->next;
            if(temp!=NULL)
            {
                newlist->next=temp->next;
            }
            newlist=newlist->next;
        }
        return ans;
    }
};
