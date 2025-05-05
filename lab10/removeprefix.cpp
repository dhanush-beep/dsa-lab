#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int t;
    cout<<"enter the number of testcases\n";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the number of elements in the series: \n";
        cin>>n;
        int a[n];
        cout<<"enter the elements of the series\n";
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        unordered_set<int>seen;
        int moves=0;
        for(int i= 0; i<n; i++)
        {
            while(seen.find(a[i])!=seen.end())
            {
                seen.erase(a[moves]);
                moves++;
            }
            seen.insert(a[i]); 
        }
        
        cout<<"no of moves taken "<<moves<<"\n";
    }

    return 0;
}