#include<iostream>
#include<stdlib.h>
using namespace std;

class cll
{
private:
    struct node
    {
        
        int data;
        struct node *next;
    }*head,*tail;

    
public:
    cll()
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
int cll::insertbeg(int val)
{
    list.assigntail();
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head == nullptr)
    {
        newnode->data=val;
        newnode->next=newnode;
        head=newnode;
    }
    else{
        newnode->data=val;
        newnode->next=head;
        head=newnode;
        tail->next=head;
    }
    
    return 0;
}// time complexity = O(n)

//method to insert at end
int cll::insertend(int val)
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
        newnode->next=head;
        tail->next=newnode;
    }
    
    return 0;

}//time complexity = O(n)

//method to insert at position
int cll::insertpos(int val, int pos)
{
    int size=list.digit();
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *temp=head;
    
    if(pos==0 || size==0)
    {
        list.insertbeg(val);
        return 0;
    }
    else if(pos>size)
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
        temp->next=newnode;
        

    }
    
    return 0;

}//time complexity = O(n)

//method to delete at begining
int cll::deletebeg()
{   
    list.assigntail();
    struct node* temp=head;
    if(head==nullptr)
    {
        cout<<"list is empty";
    }
    else if(head->next==head)
    {
        free(head);
        head=nullptr;
    }
    else
    {
        head=head->next;
        free(temp);
        tail->next=head;
    
    }
    return 0;
}//time complexity = O(n)

//method to delete at end
int cll::deleteend()
{   
    struct node *temp=head;
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
        while (temp->next->next!=nullptr)
        {
            temp=temp->next;
            
        }
        free(temp->next);
        temp->next=head;
        

    }
    return 0;
}// time complexity = o(n)

int cll::deletepos(int pos)
{   
    int size=list.digit();
    struct node *temp=head;
    struct node *temp2=head;
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
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=temp->next;
        free(temp);
        
    }

    return 0;
}// time  complexity = O(n)

int cll::display()
{   
    if(!head)
    {
        cout<<"list is empty\n";
        return 0;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int size=list.digit();
    for(int i=0; i<size;i++)
    {   
        
        
        cout<<temp->data;
        temp=temp->next;
        if(temp!=head)
        {
            cout<<"->";   
        }
    }
    list.assigntail();
    cout<<endl<<endl<<tail->next->data<<endl;
    return  0;
}// time complexity = O(n)

int cll::search(int val)
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
}// time complexity = O(n)


int cll::assigntail()
{
    struct node *temp=head;
    if (head==nullptr)
    {
        tail=nullptr;
    }
    else{
        while(temp->next!=head)
        {   
            
            temp=temp->next;
        }
        tail=temp;
    }

    
    return 0;
}

int cll::digit()
{
    int size=1;
    struct node *temp=head;
    if(head==nullptr)
    {
        return 0;
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
            size++;
        }

    }
    return size;
}