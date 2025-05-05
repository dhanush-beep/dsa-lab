//To implement a singly linked list in C++
#include <iostream>
using namespace std;

// Classes
class SinglyLinkedList{
private:
    struct node{
        int data;
        node* next;//Same as below
    };
    node * head;//we dont need struct as it is already given inside the class
public:
SinglyLinkedList();//Constructor
//Function Declaration
void insertbeginning(int beginning);
void insertend(int end);
void insertposition(int position,int posnum);
void deletebeginning();
void deleteend();
void deleteposition(int position);
void search(int key);
void display();
void revrecursion(node*temp);
void displayreverse();
void reverse();
};

int main(){
    int choice,beginning,end,position,posnum,key;
SinglyLinkedList sl;
while (1){
    cout<<"\n\n          Menu\n"<<endl;
    cout<<"1.Insert Beginning"<<endl;
    cout<<"2.Insert End"<<endl;
    cout<<"3.Insert Position"<<endl;
    cout<<"4.Delete Beginning"<<endl;
    cout<<"5.Delete End"<<endl;
    cout<<"6.Delete Position"<<endl;
    cout<<"7.Search"<<endl;
    cout<<"8.Display"<<endl;
    cout<<"9.Display Reverse"<<endl;
    cout<<"10.Reverse Link"<<endl;
    cout<<"11.Exit"<<endl;
    cout<<"Enter the option you want to choose: ";
    cin>>choice;
    switch (choice){
        case 1:
            cout<<"Enter the number to be inserted at the beginning: ";
            cin>>beginning;
            sl.insertbeginning(beginning);
            break;
        case 2:
            cout<<"Enter the number to be inserted at the end: ";
            cin>>end;
            sl.insertend(end);
            break;
        case 3:
            cout<<"Enter the position for the number to be inserted: ";
            cin>>position;
            cout<<"Enter the number to be inserted at "<<position<<" : ";
            cin>>posnum;
            sl.insertposition(position,posnum);
            break;
        case 4:
            sl.deletebeginning();
            break;
        case 5:
            sl.deleteend();
            break;
        case 6:
            cout<<"Enter the positon you want to delete : ";
            cin>>position;
            sl.deleteposition(position);
            break;
        case 7:
            cout<<"Enter the value you want to search in the list";
            cin>>key;
            sl.search(key);
            break;
        case 8:
            sl.display();
            break;
        case 9:
            sl.displayreverse();
            break;
        case 10:
            sl.reverse();
            break;
        case 11:
            cout<<"Exiting ..."<<endl;
            cout<<"Program Successfully Exited"<<endl;
            return 0;
        default:
        cout<<"Invalid option entered , Enter a valid option";
            break;
    }
}
    return 0;
}

//Constructor definition
SinglyLinkedList::SinglyLinkedList(){
    head=nullptr;
}
void SinglyLinkedList::insertbeginning(int beginning){
    node * newnode=new (nothrow)node;
    if(!newnode){
        cout<<"Memory allocation failed";
        return;
    }
    newnode->data=beginning;
    newnode->next=head;
    head=newnode;
    cout<<"The number "<<beginning<<" is Successfully inserted in the beginning";
}

void SinglyLinkedList::insertend(int end){
    node*newnode=new(nothrow)node;
    if(!newnode){
        cout<<"Memory allocation failed";
        return;
    }
    newnode->data=end;
    newnode->next=nullptr;
    if (head==nullptr){
        head=newnode;
    }else{
        node*temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    cout<<"The number "<<end<<" is successfully inserted at the end ";
}

void SinglyLinkedList::insertposition(int position, int posnum){
    node*newnode=new(nothrow)node;
    if (!newnode) {
        cout << "Memory allocation failed";
        return;
    }    
    newnode->data=posnum;
    if (position==1){
        newnode->next=head;
        head=newnode;
        cout << "The number " << posnum << " is successfully inserted at position " << position;
        return;
    }
    node *temp=head;//For going to position-1 node
    int count=1;
    while(temp!=nullptr&&count<position-1){
        temp=temp->next;
        count++;
    }
    if (temp==nullptr){
        cout<<"Invalid position!!. The list is shorter than "<<position;
        delete newnode;
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    cout << "The number " << posnum << " is successfully inserted at position " << position;
    return;
}

void SinglyLinkedList::deletebeginning(){
    if (head==nullptr){
        cout<<"The list is already empty , nothing to delete";
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
    cout<<"The first element of the list has been successfully deleted";
}

void SinglyLinkedList::deleteend(){
    if (head==nullptr){
        cout<<"The List is already empty, nothing to delete";
        return;
    }
    if (head->next==nullptr){//For one element case
        delete head;
        head=nullptr;
        return;
    }
    node*temp=head;
    while (temp->next->next!=nullptr){//We use second before ptr to prevent dangling ptr
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    cout << "The last element has been successfully deleted";

    
}
void SinglyLinkedList::deleteposition(int position){
    if (head==nullptr){
        cout<<"The list is empty,Nothing to delete";
        return;
    }
    if (position==1){
        deletebeginning();
        return;
    }
    //To go to position-1 th node
    node * temp=head;
    int count=1;
    while (temp->next!=nullptr&&count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if (temp==nullptr||temp->next==nullptr){
        cout<<"Invalid position entered!!";
        return;
    }
    node* delnode=temp->next;
    temp->next=delnode->next;
    delete delnode;
    

}

void SinglyLinkedList::search(int key){
    if (head==nullptr){
        cout<<"The list is empty, Nothing to search";
        return;
    }
    node * temp= head;
    int position=1;
    while(temp!=nullptr){
        if (temp->data==key)
        {
            cout<<"The "<<key<<" is found at position "<<position;
            return;
        }
        temp=temp->next;
        position++;
    }
    cout<<"The element "<<key<<" Not found in the list ";
}

void SinglyLinkedList::display(){
    if (head==nullptr){
        cout<<"The list is empty!!";
        return;
    }
    node*temp=head;
    cout<<"The List: ";
    while (temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
    
}

void SinglyLinkedList::revrecursion(node* temp){
    if (temp==nullptr){
        return;
    }
    revrecursion(temp->next);
    cout<<temp->data<<" -> ";
}

void SinglyLinkedList::displayreverse(){
    if (head==nullptr){
        cout<<"The list is empty!!";
        return;
    }
    cout<<"Reversed List: ";
    revrecursion(head);
    cout<<"Null"<<endl;

}

void SinglyLinkedList::reverse(){
    node*prev=nullptr;
    node*current=head;
    node*next=nullptr;
    while (current!=nullptr)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
//Time complexity for each operation
/*
Insert at Beginning	        : O(1)
Insert at End	            : O(n)
Insert at Position	        : O(n)
Delete from Beginning	    : O(1)
Delete from End	            : O(n)
Delete from Position	    : O(n)
Search	                    : O(n)
Display	                    : O(n)
Display Reverse (Recursive)	: O(n)
Reverse (Iterative)	        : O(n)
*/