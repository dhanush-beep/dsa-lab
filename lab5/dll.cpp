#include<iostream>
#include<stdlib.h>
using namespace std;

class dll
{
private:
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    }*head,*tail;

    
public:
    dll()
    {
        head=nullptr;
        tail=nullptr;
    }
    int digit();
    int assigntail();
    int display();
    int insertbeg(int val);
    int insertend(int val);
    int insertpos(int val, int pos);
    int deletebeg();
    int deleteend();
    int deletepos(int pos);
    int search(int val);
}list;



int main()
{
    cout<<"welcome to the program\n";

    while(true)
    {
        cout<<"\n\nenter the respective number to do the following operations\n";
        cout<<"1.display\n2.insert at beginning\n3.insert at end\n4.insert at position\n5.delete at beginnning\n6.delete at end\n7.delete at position\n8.search\n9.exit\n";
        int val,num,pos;
       
        cin>>val;
        switch (val)
        {
            case 2:
            cout<<"enter the value to be inserted\n";
            cin>>val;
            list.insertbeg(val);
            break;

            case 3:
            cout<<"enter the value to be inserted\n";
            cin>>val;
            list.insertend(val);
            break;

            case 4:
            cout<<"enter the value to be inserted and the position\n";
            cin>>val>>pos;
            list.insertpos(val,pos);
            break;
            
            case 5:
            list.deletebeg();
            break;

            case 6:
            list.deleteend();
            break;

            case 7:
            cout<<"enter the position foe deletion\n";
            cin>>pos;
            list.deletepos(pos);
            break;

            case 1:
            list.display();
            break;

            case 8:
            cout<<"enter the value to search";
            cin>>val;
            list.search(val);
            break;

           
            
            case 9:
            cout<<"end of the program\n";
            return 0;

            default:
            cout<<"invalid input\n";

            
        }
    }
}

//methods to inert at beginning
int dll::insertbeg(int val)
{
    list.assigntail();
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head == nullptr)
    {
        newnode->data=val;
        newnode->next=nullptr;
        newnode->prev=nullptr;
        head=newnode;
    }
    else{
        newnode->data=val;
        newnode->next=head;
        newnode->prev=nullptr;
        head->prev=newnode;
        head=newnode;
    }
    
    return 0;
}//time complexity = O(1)

//method to insert at end
int dll::insertend(int val)
{
    list.assigntail();
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(head==nullptr)
    {
        list.insertbeg(val);
        return 0;
    }
    else
    {
        newnode->data=val;
        newnode->next=nullptr;
        newnode->prev=tail;
        tail->next=newnode;
    }
    
    return 0;

}//time complexity = O(1)

//method to insert at position
int dll::insertpos(int val, int pos)
{
    int size=list.digit();
    
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head;
  
    
    if(pos==0 || size==0)
    {
        list.insertbeg(val);
        return 0;
    }
    else if(pos>size || pos<0)
    {
        cout<<"invalid position";
        return 0;
    }
    else if (pos==size)
    {
        list.insertend(val);
        return 0;
    }
    else
    {   
        for(int i=1; i<pos; i++)
        {
            
            temp=temp->next;
        }
        newnode->data=val;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
        

    }
    
    return 0;

}//time complexity= O(n)

//method to delete at begining
int dll::deletebeg()
{   
    if(head==nullptr)
    {
        cout<<"list is empty";
    }
    else if(head->next==nullptr)
    {
        free(head);
        head=nullptr;
    }
    else
    {
        head=head->next;
        free(head->prev);
        head->prev=nullptr;
    }
    return 0;
}// time complexity = O(1)

//method to delete at end
int dll::deleteend()
{   
    list.assigntail();
    if(head==nullptr)
    {
        cout<<"list is empty";
        return 0;
    }
    else if(head==tail)
    {
        list.deletebeg();
        return 0;
    }
    else
    {
        tail->prev->next=nullptr;
        free(tail);
    }
    return 0;
}//time complexity = O(1)

int dll::deletepos(int pos)
{   
    int size=list.digit();
    struct node *temp=head;
    if(pos==1)
    {
        list.deletebeg();
        return 0;
    }
    else if(pos>size || pos<1)
    {
        cout<<"invalid position";
        return 0;
    }
    else if(pos==size)
    {
        list.deleteend();
    }
    else
    {
        for(int i=1; i<pos; i++)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        
    }

    return 0;
}//time complexity = O(n)

int dll::display()
{   
    if(!head)
    {
        cout<<"list is empty\n";
        return 0;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    
    while(temp!=nullptr)
    {   
        
        
        cout<<temp->data;
        temp=temp->next;
        if(temp!=nullptr)
        {
            cout<<"<->";   
        }
    }

    return  0;
}// time complexity = O(n)

int dll::search(int val)
{   
    int size=list.digit();
    list.assigntail();
    struct node *temp=head;
    if(head->data==val)
    {
        cout<<"your value "<<head->data<<"is in 1 st position";
    }
    else if (tail->data==val)
    {
        cout<<"your value "<<val<<"is in "<<size<<" th position";
    }
    else
    {   size=1;
        while(temp->data!=val)
        {
            temp=temp->next;
            size++;
        }
        cout<<"your value "<<val<<" is in "<<size<<" th position ";
    }
    return 0;
}//time complexity = O(n)


int dll::assigntail()
{
    struct node *temp=head;
    if (head==nullptr)
    {
        tail=nullptr;
    }
    else{
        while(temp->next!=nullptr)
        {   
            
            temp=temp->next;
        }
        tail=temp;
    }

    
    return 0;
}

int dll::digit()
{
    int size=1;
    struct node *temp=head;
    if(head==nullptr)
    {
        return 0;
    }
    else
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
            size++;
        }

    }
    return size;
}
