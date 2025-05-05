//menu driven program for sorting
#include<iostream>
#include<algorithm>
using namespace std;

int menu(int arr[],int len);
int bubble(int arr[], int len);
int selection(int arr[],int len);
int insertion(int arr[],int len);
int printarr(int arr[],int len);

int main()
{
    int arr[5],len;
    cout<<"enter how many elements you need in the array\n";
    cin>>len;
    cout<<"enter the new array with "<<len<<" elements"<<endl;
    for(int i=0; i<len; i++)
    {
        cin>>arr[i];
    }
    menu(arr,len);
    return 0;
}

//menu function
int menu(int arr[], int len)
{   int num;
    cout<<"menu:"<<endl<<"1.about"<<endl<<"2.bubble sort"<<endl<<"3.selection sort"<<endl<<"4.insertion sort"<<endl<<"5.dispay list elements"<<endl<<"6.exit"<<endl;
    cout<<"enter the number in the list"<<endl;
    cin>>num;
    if(num==1 || num==2 || num==3 || num==4 ||num==5 || num==6)
    {
        switch(num)
        {
            case 1:
                cout<<"this is a menu driver which is used to select the user which sorting algorithm is used";
                menu(arr,len);
               break;
            
            case 2:
                bubble(arr,len);
                
                break;
                
            
            case 3:
            selection(arr,len);
             break;

            case 4:
            insertion(arr,len);
             break;

            case 5:
            printarr(arr,len);
            menu(arr,len);
            break;

            case 6:
            cout<<"end of the program"<<endl;
            break;

        }

    }
    else
    {
        cout<<"input is invalid";
    }
    return 0;
}

//bubble sort function
int bubble(int arr[], int len)
{   
    int temp;
    for(int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    return menu(arr,len);
}

//selection sort function
int selection(int arr[],int len)
{
    int min;
    for(int i=0; i<len-1; i++)
    {
        min=i;
        for(int j=i+1; j<len; j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;cout<<"hi";
            }
        }

        if(arr[min]<arr[i])
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;            
        }
    }
    return menu(arr,len);
}

//insertion sort function
int insertion(int arr[],int len)
{
    int key,j;
    for(int i=1; i<len; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return menu(arr,len);
}

//function to print the array
int printarr(int arr[],int len)
{
    for(int i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}