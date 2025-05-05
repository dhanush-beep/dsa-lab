#include<iostream>
using namespace std;
int main()
{
    int t;
    cout<<"enter the number of testcases\n";
    cin>>t;
    while(t--)
    {
        int k,q;
        cout<<"enter the no of elements that need to be eliminated\n";
        cin>>k;
        cout<<"enter the no of querries\n";
        cin>>q;
        int key[k];
        int arr[q];
        cout<<"enter the elements to be eliminated\n";
        for(int i=0; i<k; i++)
        {
            cin>>key[i];
        }
        cout<<"enter the querries \n";
        for(int i=0; i<q; i++)
        {
            cin>>arr[i];
            if(key[0]>arr[i])
            {
                cout<<"the no of winners in this querry is "<<arr[i]<<"\n";
            }
            else
            {
                cout<<"the no of winners in this querry is "<<key[0]-1<<"\n";
            }
        }

    }
    return 0;
}
