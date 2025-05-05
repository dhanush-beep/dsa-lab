#include<iostream>
using namespace std;
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

    return 0;
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
    return 0;
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
    return 0;
}
