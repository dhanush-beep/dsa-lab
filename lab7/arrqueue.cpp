#include <iostream>
#define MAX 5
using namespace std;

class Queue{
    private:
        int arr[MAX];
        int front=-1,rear=-1;
    public:
        void enqueue(int);
        void dequeue();
        void peek();
}queue;

int main(){
    int ch=0,value;
    cout<<"************ MENU ************\n\n";
    cout<<"1 -> enqueue\n";
    cout<<"2 -> dequeue\n";
    cout<<"3 -> peek\n";
    cout<<"4 -> exit\n\n";
    while(ch!=4){
        cout<<"enter yintour choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            /* code */
            cout<<"enter a value to enqueue : ";
            cin>>value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            cout<<"\n\n\nsuccessfully completed\n\n\n";
            break;
        default:
            break;
        }
    }
}

void Queue::enqueue(int value){
    if (rear==MAX-1){
        cout<<"\n\n\noverflow\n\n\n";
        return;
    }
    if(front==-1){
        arr[++front]=value;
        ++rear;
        cout<<"\n\n\nenqueued successfully\n\n\n";
        return;
    }
    arr[++rear]=value;
    cout<<"\n\n\nenqueued successfully\n\n\n";
    return;
}

void Queue::dequeue(){
    int key;
    if (front==-1){
        cout<<"\n\n\nunderflow\n\n\n";
        return;
    }key=arr[front];
    for (int i=0;i<rear;i++){
        arr[i]=arr[i+1];
    }
    cout<<"\n\n\ndequeued value is "<<key<<"\n\n\n";
    return;
}

void Queue::peek(){
    if(front==-1){
        cout<<"\n\n\nunderflow\n\n\n";
        return;
    }
    cout<<"\n\n\nthe peek value is "<<arr[front]<<"\n\n\n";
    return;
}