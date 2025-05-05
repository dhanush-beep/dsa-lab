#include<iostream>
using namespace std;
int main()
{
    cout<<"enter the no of test cases\n";
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the number of participants\n";
        cin>>n;
        int arr[n];
        int max1=0;
        int max2=0;
        int maxindex=-1;
        for(int i=0; i<n; i++)
        {
            cout<<"enter the strength of particiant"<<i+1<<"\n";
            cin>>arr[i];
            
            if(arr[i]>=max1)
            {
                max2=max1;
                max1=arr[i];
                maxindex=i;
            }
            else if(arr[i]>=max2)
            {
                max2=arr[i];
            }

        }
        for(int i=0; i<n; i++)
        {
            if (arr[i]==max1)
            {
                cout<<"advantage of participant "<<i+1<<" is "<<max1-max2<<"\n";
            }
            else
            {
                cout<<"advantage of participant "<<i+1<<" is "<<arr[i]-max1<<"\n";
            }

        }
    }
    return 0;
}