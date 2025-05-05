#include<iostream>
#define size 5
using namespace std;

class stack
{
    int arr[size];

    public:

    int top=-1;

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
    
    if(top==size-1)
    {
        cout<<"stack overflow\n";
        return 0;
    }
    else
    {
        arr[++top]=val;
        cout<<"value is pushed\n";
    }
    return 0;
}

int stack::pop()
{
    if(top==-1)
    {
        cout<<"stac underflow\n";
        return 0;
    }
    else
    {
        cout<<arr[top--]<<" is poped\n";
    }
    return 0;
}

int stack::peek()
{
    if(top==-1)
    {
        cout<<"stack is underflow\n";
        return 0;
    }
    else
    {
        cout<<arr[top]<<" is the top element\n";
    }
    return 0;
    
}

int stack::display()
{
    if(top==-1)
    {
        cout<<"stack is empty\n";
    }
    else{
        int temp=top;
        while (top!=-1)
        {
            cout<<"       |"<<arr[top]<<"|\n ";
            top--;
        }
        top=temp;
    }
    cout<<"\n";
    return 0;
}