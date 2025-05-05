


#include<iostream>
using namespace std;
class stack
{
    struct node
    {
        int data;
        struct node *next;
    }*top;

    public:
    stack()
    {
        top=nullptr;
    }
    
    
    int push(int val);
    int pop();
    int peek();
    int display();

}list;

int main()
{
    int num,val;
    while(true)
    {
        
        cout<<"menu\n";
        cout<<"1.push\n2.pop\n3.peek\n4.display\n5.exit\n";
        cout<<"enter the respective number to follow the operation\n";
        cin>>num;
        switch (num)
        {
            case 1:
            cout<<"enter the value to be pushed\n";
            cin>>val;
            list.push(val);
            break;

            case 2:
            list.pop();
            break;
        
            case 3:
            list.peek();
            break;

            case 4:
            list.display();
            break;

            case 5:
            cout<<"end of the program";
            return 0;

            default:
            cout<<"invalid input";
        }

    }
}

int stack::push(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    
    return 0;
}

int stack::pop()
{   
    if(top==nullptr)
    {
        cout<<"stack underflow\n";
        return 0;
    }
    struct node *temp=top;
    top=top->next;
    cout<<temp->data<<" is poped\n";
    free(temp);
    
    return 0;
}

int stack::peek()
{   
    if(top==nullptr)
    {
        cout<<"stack is empty\n";
    }else
    {
        cout<<top->data<<" is the top element\n";
    }
    return 0;
    
}

int stack::display()
{
    if(top==nullptr)
    {
        cout<<"stack is empty";
    }
    struct node *temp=top;
    while(temp!=nullptr)
    {
        cout<<"      |"<<temp->data<<"|\n";
        temp=temp->next;
    }
    cout<<"\n";
    return 0;
}
