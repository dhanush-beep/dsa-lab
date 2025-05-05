//menu driven program for sorting
#include<iostream>
#include<algorithm>
#include"sort.h"
using namespace std;

int linear(int arr[],int len,int key);
int binary(int arr[],int len,int key);
int menu(int arr[],int len,int key);

int main()
{   
    int arr[5],len,key;
    cout<<"enter how many elements you need in the array\n";
    cin>>len;
    cout<<"enter the new array with 5 elements"<<endl;
    for(int i=0; i<len; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the search key element"<<endl;
    cin>>key;
    menu(arr,len,key);
    return 0;
}

//menu function
int menu(int arr[], int len,int key)
{   int num;
    cout<<"menu:"<<endl<<"1.about"<<endl<<"2.linear search"<<endl<<"3.binary search"<<endl<<"4.exit"<<endl;
    cout<<"enter the number in the list"<<endl;
    cin>>num;
    if(num==1 || num==2 || num==3 || num==4 ||num==5 || num==6)
    {
        switch(num)
        {
            case 1:
                cout<<"this is a menu driver which is used to select the user which sorting algorithm is used";
                menu(arr,len,key);
               break;
            
            case 2:
            linear(arr,len,key);
            break;

            case 3:
            binary(arr,len,key);
            break;

            case 4:
            cout<<"end of the program";
            break;
        }

    }
    else
    {
        cout<<"input is invalid";
    }
    return 0;
}

int linear(int arr[],int len,int key)
{
    for(int i=0;i<len; i++)
    {
        if(key==arr[i])
        {
            cout<<"the key element is in "<<i+1<<"th position"<<endl;
        }
    }
    return menu(arr,len,key);
}
int binary(int arr[],int len,int key)
{
    bubble(arr,len);
    cout<<"array is sorted using imported module:\n";
    for(int i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    int high=len-1, low=0,mid;
    

    while(true)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            cout<<"the key element is in "<<mid+1<<"th position of the sorted array"<<endl;
            return 0;
        }
        else if(key<arr[mid])
        {   
            high=mid-1;
        }
        else 
        {   cout<<"ko";
            low=mid+1;
        }
        
    }
    cout<<"element not found"<<endl;
    return 0;
}
